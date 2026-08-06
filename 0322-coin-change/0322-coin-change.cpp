class Solution {
private:
    int t[10001];
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, -2);
        res[0] = 0;
        for(int i = 1; i < amount + 1; ++i) {
            for(int j = 0; j < coins.size(); ++j) {
                // cout<<i<<" "<<j<<endl;
                if(i - coins[j] >= 0 && res[i - coins[j]] != -1) {
                    if(res[i] == -2)
                        res[i] = res[i - coins[j]] + 1;
                    else
                        res[i] = min(res[i], res[i - coins[j]] + 1);
                }
            }
            if(res[i] == -2) {
                // cout<<i<<" "<<endl;
                res[i] = -1;
            }      
        }

        return res[amount];
    }
};