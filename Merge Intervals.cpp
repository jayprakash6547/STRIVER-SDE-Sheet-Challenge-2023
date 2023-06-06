#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
        // Sort intervals based on start time
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    vector<vector<int>> mergedIntervals;

    // Iterate over intervals
    for (const auto& interval : intervals) {
        if (mergedIntervals.empty() || interval[0] > mergedIntervals.back()[1]) {
            // No overlap, add new interval
            mergedIntervals.push_back(interval);
        } else {
            // Overlap, update end time of last merged interval
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
        }
    }

    return mergedIntervals;
}
