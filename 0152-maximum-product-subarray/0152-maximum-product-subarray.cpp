class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int ans = *max_element(begin(nums), end(nums));
       int curmax = 1;
       int curmin = 1;

       for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] == 0) {
            curmax = 1;
            curmin = 1;
            continue;
        }
        int t = curmax * nums[i];
        curmax = max(nums[i] * curmax, max(nums[i] * curmin, nums[i]));
        curmin = min(t, min(nums[i] * curmin, nums[i]));
        ans = max(ans, curmax);
        cout<<curmax<<" "<<curmin<<" "<<ans<<endl;
       }
       return ans;

    }
};
