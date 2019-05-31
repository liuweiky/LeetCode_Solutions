class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        
        if (intervals.size() == 0)
            return ans;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<int> last = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (last[1] >= intervals[i][0])
                last[1] = max(intervals[i][1], last[1]);
            else
            {
                ans.push_back(last);
                last = intervals[i];
            }
        }
        
        ans.push_back(last);
        
        return ans;
    }
};
