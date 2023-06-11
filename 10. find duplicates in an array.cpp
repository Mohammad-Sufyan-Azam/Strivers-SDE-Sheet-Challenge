#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	// hare and tortoise
	int slow = arr[0], fast = arr[0];
	while(true) {
		slow = arr[slow];
		fast = arr[arr[fast]];
		if (slow == fast)
			break;
	} 
	fast = arr[0];
	while(fast != slow) {
		fast = arr[fast];
		slow = arr[slow];
	}
	return fast;
}
