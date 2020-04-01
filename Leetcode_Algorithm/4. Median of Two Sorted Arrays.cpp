#include <iostream>
#include <vector>
#include <queue>
using namespace std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	for (int i = 0; i < nums1.size(); ++i) {
		if (max_heap.size() == min_heap.size())
			max_heap.push(nums1[i]);
		else
			min_heap.push(nums1[i]);

		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
			int maxt = max_heap.top();
			int mint = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(mint);
			min_heap.push(maxt);
		}
	}

	for(int i = 0; i < nums2.size(); ++i) {
		if (max_heap.size() == min_heap.size())
			max_heap.push(nums2[i]);
		else
			min_heap.push(nums2[i]);

		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
			int maxt = max_heap.top();
			int mint = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(mint);
			min_heap.push(maxt);
		}
	}

	if (max_heap.size() == min_heap.size())
		return ((double)max_heap.top() + (double)min_heap.top()) / 2;
	else {
		if(max_heap.size() > min_heap.size())
			return (double)max_heap.top();
		else
			return (double)min_heap.top();
	}
}

int main() {

	cout << findMedianSortedArrays({1,3}, {2});
	return 0;
}