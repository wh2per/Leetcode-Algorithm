#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ans;

	for (int i = 0; i < nums.size() - 1; ++i) {
		for (int j = i + 1; j < nums.size(); ++j) {
			if (nums[i] + nums[j] == target) {
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
	}
	return ans;

}
int main() {
	vector<int> input = {2,7,11,15};
	vector<int> ans = twoSum(input,9);
	for (auto a : ans)
		cout << a << endl;
		
	return 0;
}