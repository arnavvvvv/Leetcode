class Solution {
    int m[2501][2501];
    int dp(vector<int>& nums, int key, int idx) {
        if(idx >= nums.size())
            return 0;
        if(key != 0 && m[key][idx] != -1) {
            return m[key][idx];
        }
        
        if(key != 0 && nums[idx] <= nums[key - 1]) {
            // cout<<"inside"<<key<<" "<<nums[idx]<<endl;
            return dp(nums, key, idx + 1);
        }
            
        // cout<<key<<" "<<nums[idx]<<endl;
        return m[key][idx] =  max(1 + dp(nums, idx + 1, idx + 1), dp(nums, key, idx + 1));
        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int key = 0;
        memset(m,-1, sizeof(m));
        return dp(nums, 0, 0);
    }
};