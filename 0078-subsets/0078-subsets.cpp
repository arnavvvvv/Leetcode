class Solution {
private:
    void solve(vector<vector<int>>& res, vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            vector<int> t;
            for(int x: nums) {
                if(x!= -11)
                    t.push_back(x);
            }
            res.push_back(t);
            return;
        }
        solve(res, nums, idx + 1);
        int t = nums[idx];
        nums[idx] = -11;
        solve(res, nums, idx + 1);
        nums[idx] = t;
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        
        solve(res, nums, 0);
        return res;
    }
};
