#include <bits/stdc++.h> 
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long sum = 0, runningSum = 0;
    for(int i=0; i<n; i++) {
        runningSum += arr[i];
        sum = max(runningSum, sum);
        if (runningSum < 0)
            runningSum = 0;
    }
    return sum;
}