class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        // if(intervals.size() == 0)
        //     return vector<vector<int>>({newInterval});
        bool added = false;
        
       
        for(int i = 0; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if(!added && newInterval[0] <= intervals[i][0]) {
                interval = newInterval;
                added = true;
                --i;
            }
                
            if(res.size() && interval[0] <= res.back()[1])
                res.back()[1] = max(interval[1], res.back()[1]);
            else
                res.push_back(interval);
        }
        if(!added) {
             if(res.size() && newInterval[0] <= res.back()[1])
                res.back()[1] = max(newInterval[1], res.back()[1]);
            else
                res.push_back(newInterval);
        }
           
        return res;
        
    }
};
