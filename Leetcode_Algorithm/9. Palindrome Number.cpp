#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int x) {
	if (x < 0)
		return false;

	string num = to_string(x);
	int len = num.length() / 2;

	int start = 0;
	int end = num.length() - 1;
	for (int i = 0; i < len; ++i) {
		if (num[start + i] != num[end - i])
			return false;
	}

	return true;
}

int main() {
	cout << isPalindrome(121);

	return 0;
}