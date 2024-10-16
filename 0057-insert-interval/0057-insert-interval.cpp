class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        // Add all intervals that come before the newInterval
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        // Merge intervals that overlap with newInterval
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        // Add all intervals that come after the newInterval
        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
