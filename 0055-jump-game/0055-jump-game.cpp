class Solution {
private:
    vector<int> cache = vector<int>(10001, -1);
    bool dp(vector<int>& nums, int idx) {
        if(idx >= nums.size() - 1)
            return true;
        if(cache[idx] != -1)
            return bool(cache[idx]);
        int jump = nums[idx];
        for(int i = 1; i <= jump; ++i) {
            if(dp(nums, idx + i))
                return cache[idx] = true;
        }
        return cache[idx] = false;
    }
public:
    bool canJump(vector<int>& nums) {

        return dp(nums, 0);
       
    }
};
