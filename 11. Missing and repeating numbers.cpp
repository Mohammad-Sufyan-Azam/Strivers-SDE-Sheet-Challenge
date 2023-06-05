#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	// O(n), O(n)
	// unordered_map<int, int> hash;
	// int missing = 0, repeating = 0;
	// for(int i=0; i<n; i++) {
	// 	hash[arr[i]]++;
	// 	if (hash[arr[i]] > 1)
	// 		repeating = arr[i];
	// }
	
	// for(int i=1; i<=n; i++) {
	// 	missing ^= i ^ arr[i-1];
	// }
	// missing ^= repeating;

	// return {missing, repeating};

	// O(n), O(n)
	long long sum_N = (n * 1LL* (n + 1))/2;
	long long sum_N_sq = (n * 1LL* (n + 1) * 1LL* (2*n + 1)) / 6;
	for(int i=0; i<n; i++) {
		sum_N -= arr[i];
		sum_N_sq -= arr[i] * 1LL * arr[i];
	}
	// x = missing, y = repeating;
	// therefore, x - y = sum_N; 
	//   and, x_sq - y_sq = sum_N_sq; => (x + y)(x - y) = sum_N_sq; => x + y = sum_N_sq / sum_N;
	// therefore, x = (sum_N_sq/sum_N + sum_N)/2; and y = (sum_N_sq/sum_N - sum_N)/2;
	int x = (sum_N_sq/sum_N + sum_N) / 2;
	int y = sum_N_sq/sum_N - x;

	return {x, y};
}
