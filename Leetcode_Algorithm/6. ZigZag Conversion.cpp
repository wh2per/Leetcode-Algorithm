#include <string>
#include <vector>
#include <iostream>
using namespace std;

string convert(string s, int numRows) {
	if (numRows == 1)
		return s;
	vector<string> ans(numRows, "");

	int add = 1;
	int index = 0;
	int count = 1;

	for (int i = 0; i < s.length(); ++i) {
		ans[index] += s[i];
		if (count == numRows) {
			add *= -1;
			count = 1;
		}

		index += add;
		++count;
	}

	string answer = "";

	for (auto a : ans)
		answer += a;
	return answer;
}


int main() {

	cout << convert("AB", 1);
	return 0;
}