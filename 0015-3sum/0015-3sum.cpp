class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int h = nums.size() - 1;
            while(l < h) {
              
                if(nums[l] + nums[h] + nums[i] < 0) {
                   ++l;
                }
                else if(nums[l] + nums[h] + nums[i] > 0) {
                   --h;
                }
                else if(nums[l] + nums[h] + nums[i] == 0) {
                    res.push_back({nums[i], nums[l], nums[h]});
                    while(l < h && nums[l] == nums[l + 1])
                        ++l;
                    while(h > l && nums[h] == nums[h-1])
                        --h;
                    ++l;
                    --h;
                }

            }
        }
        
        return res;

        

    }
};