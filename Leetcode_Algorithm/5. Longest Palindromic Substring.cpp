#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
	string ss = "";
	for (int i = 0; i < s.length(); ++i) {
		ss += "#";
		ss += s[i];
	}
	ss += "#";

	int slen = ss.length();

	int r = 0, p = 0;
	vector<int> A(slen, 0);

	for (int i = 0; i < slen; ++i) {
		if (i <= r)
			A[i] = min(A[2 * p - i], r - i);
		else
			A[i] = 0;

		while (i - A[i] - 1 >= 0 && i + A[i] < slen && ss[i - A[i] - 1] == ss[i + A[i] + 1])
			++A[i];

		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}
	}

	int ans = -1;
	int index = -1;
	for (int i = 0; i < slen; i++) {
		if (ans < A[i]) {
			ans = A[i];
			index = i;
		}
	}

	string answer = "";
	if (ans % 2 == 0) {		// Â¦¼öÀÏ °æ¿ì
		ans /= 2;
		for (int i = index- (2*ans-1); i <= index+ (2*ans-1); i += 2)
			answer += ss[i];
	}
	else {
		--ans;
		ans /= 2;
		for (int i = index - 2*ans; i <= index + 2*ans; i += 2)
			answer += ss[i];
	}

	return answer;
}

int main() {
	cout << longestPalindrome("babad");
	return 0;
}