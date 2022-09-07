class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0, n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> modified_intervals;
        modified_intervals.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            if(modified_intervals.back()[1]>=intervals[i][0]) modified_intervals.back()[1] = max(modified_intervals.back()[1], intervals[i][1]);
            else modified_intervals.push_back(intervals[i]);
        }
        return modified_intervals;
    }
};