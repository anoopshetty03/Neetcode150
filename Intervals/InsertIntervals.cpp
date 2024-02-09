class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++)
        {
            if(newInterval[1]<intervals[i][0]) //if interval to be merged is less than interval in array
            {
                ans.push_back(newInterval);
                    for(;i<n;i++)
                    {
                        ans.push_back(intervals[i]);
                    }
                return ans;
            }
            else if(intervals[i][1] < newInterval[0]) //If current interval is before newInterval
                ans.push_back(intervals[i]);
            else
            {   
                //Overlapping intervals
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};