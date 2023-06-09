#include <bits/stdc++.h>
using namespace std;

void swap(int* arr, int a, int b) {
   int temp = arr[a];
   arr[a] = arr[b];
   arr[b] = temp;
}

void sort012(int *arr, int n)
{
   //   Write your code here
   int low = 0, high = n-1;
   for(int i=0; i<=high; i++) {
      if (arr[i] == 0) {
         swap(arr, i, low);
         low++;
      }
      else if (arr[i] == 2) {
         swap(arr, i, high);
         high--;
         i--;
      }
   }
}