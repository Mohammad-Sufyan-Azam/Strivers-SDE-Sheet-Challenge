#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int min_price = INT_MAX;
    int profit = 0;
    for(int i=0; i<prices.size(); i++){
        min_price = min(min_price, prices[i]);
        profit = max(profit, prices[i] - min_price);
    }
    return profit;
}