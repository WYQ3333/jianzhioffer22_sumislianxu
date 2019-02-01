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

class Solution1 {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		int l = 1, r = 1, sumx = 1;
		vector<vector<int> > ans;
		while (l <= r){
			r++;
			sumx += r;
			while (sumx > sum){
				sumx -= l;
				l++;
			}
			if (sumx == sum && l != r){
				vector<int> tmp;
				for (int i = l; i <= r; i++)  tmp.push_back(i);
				ans.push_back(tmp);
			}
		}
		return ans;
	}
};

//左神的思路，双指针问题
//当总和小于sum，大指针继续+
//否则小指针+
class Solution3 {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > allRes;
		int phigh = 2, plow = 1;

		while (phigh > plow){
			//计算出了滑动的窗口的大小
			//左边是滑动窗口的宽度的二倍，右边是滑动窗口的长度
			int cur = (phigh + plow) * (phigh - plow + 1) / 2;
			if (cur < sum)
				phigh++;

			if (cur == sum){
				vector<int> res;
				for (int i = plow; i <= phigh; i++)
					res.push_back(i);
				allRes.push_back(res);
				plow++;
			}

			if (cur > sum)
				plow++;
		}

		return allRes;
	}
};

void TestFunc(){
	Solution3 s;
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