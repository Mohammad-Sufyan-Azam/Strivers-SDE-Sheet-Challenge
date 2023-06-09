#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	// Write your code here.
	int p1 = m-1, p2 = n-1, p3 = m+n-1;
	while(p1 >= 0 && p2 >= 0) {
		if (nums2[p2] > nums1[p1])
			nums1[p3--] = nums2[p2--];
		else
			nums1[p3--] = nums1[p1--];
	}
	while(p2 >= 0) {
		nums1[p3--] = nums2[p2--];
	}
	return nums1;
}
