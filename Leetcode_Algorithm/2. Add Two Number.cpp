#include <iostream>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

string plus_string(string a, string b) {
	string ans = "";

	int ai = a.length() - 1;
	int bi = b.length() - 1;

	bool over = false;
	while (ai != -1 && bi != -1) {
		int c = a[ai] - '0';
		int d = b[bi] - '0';

		if (over)
			++c;
		over = false;
		if (c + d > 9)
			over = true;
		ans = to_string((c + d) % 10) + ans;
		--ai;
		--bi;
	}

	if (ai >= 0) {
		while (ai != -1) {
			int c = a[ai] - '0';
			if (over)
				++c;
			over = false;
			if (c > 9)
				over = true;

			ans = to_string(c % 10) + ans;
			--ai;
		}
	}
	else if (bi >= 0) {
		while (bi != -1) {
			int c = b[bi] - '0';
			if (over)
				++c;
			over = false;
			if (c > 9)
				over = true;

			ans = to_string(c % 10) + ans;
			--bi;
		}
	}

	if (over)
		ans = "1" + ans;

	return ans;
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	string s1 = "";
	string s2 = "";

	while (l1->next != NULL) {
		s1 = to_string(l1->val) + s1;
		l1 = l1->next;
	}
	s1 = to_string(l1->val) + s1;

	while (l2->next != NULL) {
		s2 = to_string(l2->val) + s2;
		l2 = l2->next;
	}
	s2 = to_string(l2->val) + s2;
	cout << "s1 : " << s1 << endl;
	cout << "s2 : " << s2 << endl;
	string sans = plus_string(s1, s2);

	ListNode* ansNode = new ListNode(sans[sans.length() - 1] - '0');
	ListNode* answer = ansNode;
	for (int i = sans.length() - 2; i >= 0; --i) {
		ListNode* temp = new ListNode(sans[i] - '0');
		ansNode->next = temp;
		ansNode = ansNode->next;
	}

	return answer;
}

int main() {
	
	return 0;
}