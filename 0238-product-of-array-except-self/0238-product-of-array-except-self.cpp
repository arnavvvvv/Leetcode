class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> suffix(n + 1);
        // vector<int> prefix(n + 1);
        // vector<int> ans(n);
        // prefix[0] = 1;
        // suffix[n] = 1;
        // for(int i = 0; i < nums.size(); ++i) {
        //     prefix[i + 1] = prefix[i] * nums[i];
        //     suffix[n - i - 1] = suffix[n - i] * nums[n - i - 1];
        // }
        // for(int i = 0; i < nums.size(); ++i) {
        //     ans[i] = prefix[i] * suffix[i + 1];
        // }
        // return ans;
        int n = nums.size();
        vector<int> res(n);
        int prod = 1;
        res[0] = prod;
        for(int i = 0; i < n - 1; ++i) {
            prod = prod * nums[i];
            res[i + 1] = prod;
        }
        prod = 1;
        for(int i = n - 1; i > 0; --i) {
            prod = prod * nums[i];
            res[i - 1] *= prod;
        }
        return res;
        

        
    }
};