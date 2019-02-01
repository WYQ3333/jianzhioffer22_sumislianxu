#include<iostream>

#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> result;
		int i = 0;
		int index = 0;
		for (i = 0; i < sum; ++i){
			int j = i;
			int num = 0;
			for (j = i; j < sum; ++j){
				if (num < sum){
					num += j;
				}
				if (num == sum){
					int temp = i;
					for (temp = i; temp <= j; ++temp){
						result[index++].push_back(temp);
					}
				}
				if (num>sum){
					break;
				}
			}
		}
		return result;
	}
};

void TestFunc(){
	Solution s;
	vector<vector<int>> solution;
	solution = s.FindContinuousSequence(100);
	int i = 0;
	int j = 0;
	for (i = 0; i < solution.size(); ++i){
		for (j = 0; j < solution[0].size(); ++j){
			cout << solution[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}