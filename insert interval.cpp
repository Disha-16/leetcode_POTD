class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();

    // Add all intervals ending before newInterval starts
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    // Merge all overlapping intervals to one considering newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        // Updating the newInterval to the merged interval
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    // Add the merged interval
    result.push_back(newInterval);

    // Add the rest of the intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
        
    }
};
