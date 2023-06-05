#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int numRows) 
{
  // Write your code here.
  vector<vector<long long int>> res;
  if (numRows == 1) {
      vector<long long int> a;
      a.push_back(1);
      res.push_back(a);
      return res;
  }
  if (numRows == 2) {
      vector<long long int> a;
      a.push_back(1);
      res.push_back(a);
      vector<long long int> b;
      b.push_back(1);
      b.push_back(1);
      res.push_back(b);
      return res;
  }
  vector<long long int> a;
  a.push_back(1);
  res.push_back(a);
  vector<long long int> b;
  b.push_back(1);
  b.push_back(1);
  res.push_back(b);
  
  for(int n = 3; n<=numRows; n++) {
      vector<long long int> temp(n);
      temp[0] = 1;
      temp[n-1] = 1;
      for(int i=0; i<res[n-2].size()-1; i++) {
          temp[i+1] = res[n-2][i]+res[n-2][i+1];
      }
      res.push_back(temp);
  }

  return res;
}
