class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> prefix_sum;
        int count = 0;
    
        prefix_sum.push_back(nums[0]);
        for(int& x: nums | std::views::drop(1)) {
            prefix_sum.push_back(x + prefix_sum.back());
        }
        for(int& x: prefix_sum) {
            //cout<<x<<endl;
            if(m.find(x - k) != m.end())
                count += m[x - k];
            if(x == k)
                ++count;
            ++m[x];
        }
        return count;

    }
};