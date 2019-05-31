class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int ptr = 0;
        while (ptr < intervals.size() && intervals[ptr][0] < newInterval[0])
            ptr++;
        intervals.insert(intervals.begin() + ptr, newInterval);
        if (ptr > 0)
        {
            vector<vector<int>> ans(intervals.begin(), intervals.begin() + ptr - 1);
            
            vector<int> last = intervals[ptr - 1];
            for (int i = ptr; i < intervals.size(); i++)
            {
                if (last[1] < intervals[i][0])
                {
                    ans.push_back(last);
                    last = intervals[i];
                }
                else
                {
                    last[1] = max(last[1], intervals[i][1]);
                }
            }
            
            ans.push_back(last);
            return ans;
        }
        else
        {
            vector<vector<int>> ans;
            
            vector<int> last = intervals[0];
            for (int i = 1; i < intervals.size(); i++)
            {
                if (last[1] < intervals[i][0])
                {
                    ans.push_back(last);
                    last = intervals[i];
                }
                else
                {
                    last[1] = max(last[1], intervals[i][1]);
                }
            }
            
            ans.push_back(last);
            return ans;
        }
    }
};
