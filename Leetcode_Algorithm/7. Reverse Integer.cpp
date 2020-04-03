#include <iostream>
using namespace std;

int reverse(int x) {
	if (x == INT_MIN)
		return 0;
	bool flag = false;

	if (x < 0) {
		flag = true;
		x = -x;
	}

	long long end = 1;
	int len = -1;

	do {
		++len;
		end *= 10;
	} while (end <= x);

	long long ans = 0;
	int left = -1;
	while (x > 0) {
		left = x % 10;
		if (left != 0)
			ans += pow(10, len) * left;
		--len;
		if (ans > INT_MAX)
			return 0;
		x /= 10;
	}
	if (flag)
		return -(int)ans;
	else
		return (int)ans;
}

int main() {
	cout << reverse(34);
	return 0;
}