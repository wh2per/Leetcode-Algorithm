#include <iostream>
#include <string>
#include <climits>
using namespace std;

int myAtoi(string str) {
	int index = 0;
	long long ans = 0;
	bool start = false;

	// 1. 공백 제거
	for (int i = index; i < str.length(); ++i) {
		if (str[i] != ' ') {
			index = i;
			break;
		}
	}

	// 2. 부호인가?
	int sign = 0;			// 0:초기값 1:- 2:+
	if (str[index] == '-') {
		sign = 1;
		++index;
		if (str[index] == '+')
			return 0;
	}
	else if (str[index] == '+') {
		sign = 2;
		++index;
		if (str[index] == '-')
			return 0;
	}
	
	for (int i = index; i < str.length(); ++i) {
		if (str[i] >= '0' && str[i] <= '9') {		// 숫자일 경우
			start = true;
			int c = str[i] - '0';
			if (c == 0 && ans==0)		// 0이면 continue
				continue;

			if (ans != 0)
				ans *= 10;
			ans += c;

			if (sign == 1) {			// 음수일 경우
				if (ans > (long long)INT_MAX + 1)
					return INT_MIN;
			}
			else {				// 양수일 경우
				if (ans > INT_MAX)
					return INT_MAX;
			}
		}
		else 			// 문자일 경우
			break;
	}

	if (sign == 1)
		return -ans;
	else
		return ans;
}

int main() {
	cout << myAtoi("-13+8");
	return 0;
}