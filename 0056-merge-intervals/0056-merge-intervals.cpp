bool smaller_interval(vector<int>& lhs, vector<int>& rhs) {
    if(lhs[0] < rhs[0])
        return true;
    if(lhs[0] == rhs[0])
        return lhs[1] < rhs[1];
    return false;
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), smaller_interval);
        // for(auto x: intervals)
        //     cout<<x[0]<<","<<x[1]<<"   ";
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); ++i) {
            int j = i;
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(j < intervals.size() - 1 && intervals[j+1][0] <= end) {
                if(intervals[j + 1][1] > end)
                    end = intervals[j + 1][1];
                ++j;
            }
            ans.push_back({start, end});
            i = j;
               
        }
        return ans;
        
    }
};
