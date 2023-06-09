#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0], end = intervals[0][1];
    for(int i=1; i<intervals.size(); i++){
        if (end >= intervals[i][0]) {
            end = max(end, intervals[i][1]);
        }
        else {
            result.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    result.push_back({start, end});
    
    return result;
}