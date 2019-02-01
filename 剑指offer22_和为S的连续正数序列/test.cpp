#include<iostream>

#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> result = { {} };
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
						result[index].push_back(temp);
					}
					++index;
					result.resize(index+1);
					break;
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
	if (solution.empty()){
		cout << "不存在这样的数组" << endl;
	}
	else{
		int i = 0;
		int j = 0;
		int index = 0;
		for (i = 0; i < solution.size(); ++i){
			int temp = solution[index++].size();
			for (j = 0; j < temp; ++j){
				cout << solution[i][j] << " ";
			}
			cout << endl;
		}
	}
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}