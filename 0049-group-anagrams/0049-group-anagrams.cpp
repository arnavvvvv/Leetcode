class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        int i = 0;
        for(string s : strs) {
            sort(begin(s), end(s));
            m[s].push_back(strs[i]);
            ++i;
        }
        for(auto x: m) {
            res.push_back(x.second);
        }
        return res;
        
    }
};