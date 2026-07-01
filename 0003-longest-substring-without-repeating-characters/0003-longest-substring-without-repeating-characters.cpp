class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        int count = 1;
        int start = 0;
        unordered_map<int, int> m;
        m[s[0]] = 0;
        for(int i = 1; i < s.size(); ++i) {
            if(m.find(s[i]) != m.end()) {
                for(int j = start; j < m[s[i]]; ++j) {
                    m.erase(s[j]);
                }
                start = m[s[i]] + 1;
                m[s[i]] = i;
            }
            else {
                m[s[i]] = i;
                count = max(count, i - start + 1);
            }

        }
        return count;

        
    }
};