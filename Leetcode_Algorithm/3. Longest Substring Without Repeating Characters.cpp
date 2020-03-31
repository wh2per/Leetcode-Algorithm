#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(string s) {
	if (s == "")
		return  0;

	int ans = 0;
	unordered_map<int, int> um;
	int i = 0, j = 0;
	int temp = 0;

	for (i = 0; i < s.length(); ++i) {
		char c = s[i];
		if (um.count(c) == 0 || um[c] < j) {
			um[c] = i;
			++temp;
		}
		else {
			j = um[c] + 1;
			temp = i - j + 1;
			um[c] = i;
		}
		ans = max(ans, temp);
	}
	return ans;
}

int main() {
	cout << solution("pwwkew");
	return 0;
}