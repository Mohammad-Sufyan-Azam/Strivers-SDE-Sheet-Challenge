#include <bits/stdc++.h>
using namespace std;

long long int merge(long long int arr1[], long long int s1, long long int e1, 
                    long long int arr2[], long long int s2, long long int e2){

    long long int size1 = e1-s1;
    long long int size2 = e2-s2;

    long long int arr[size1+size2];
    long long int ptr1 = s1, ptr2 = s2, ptr = 0, count = 0;

    while(ptr1<e1 && ptr2<e2) {
        if (arr1[ptr1] <= arr2[ptr2])
            arr[ptr++] = arr1[ptr1++];
        else {
            arr[ptr++] = arr2[ptr2++];
            count+=e1-ptr1;
        }
    }

    while(ptr1<e1){
        arr[ptr++] = arr1[ptr1++];
    }

    while(ptr2<e2){
        arr[ptr++] = arr2[ptr2++];
    }
    long long int size3 = ptr;
    ptr = 0;
    for(ptr1=s1; ptr1<e1; ptr1++)
        arr1[ptr1] = arr[ptr++];
    
    for(ptr2=s2; ptr2<e2; ptr2++)
        arr2[ptr2] = arr[ptr++];

    return count;
}

long long int invCount(long long arr[], long long st, long long N)
{
    if (N-st <= 1){
        return 0;
    }
    if(N-st == 2) {
        if (arr[st] > arr[st+1]){
            long long int t = arr[st];
            arr[st] = arr[st+1];
            arr[st+1] = t;
            return 1;
        }
        else
            return 0;
    }
    long long int pair = 0;
    pair += invCount(arr, st, (st+N)/2);
    pair += invCount(arr, (st+N)/2, N);
    pair += merge (arr, st, (st+N)/2, arr, (st+N)/2, N);
    return pair;
}

long long getInversions(long long *arr, int n){
    // Write your code here.    
    long long int start = 0;
    return invCount(arr, start, n);
}