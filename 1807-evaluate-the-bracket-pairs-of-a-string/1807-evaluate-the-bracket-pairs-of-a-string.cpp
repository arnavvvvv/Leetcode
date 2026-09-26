class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        string ans;
        for(auto x: knowledge)
            m[x[0]] = x[1];
        bool bracket = false;
        string t;
        for(int i = 0; i< s.size(); ++i) {
            if(s[i] == '(') {
                bracket = true;
            }
            else if(s[i] == ')') {
                if(m.count(t))
                    ans += m[t];
                else
                    ans += "?";
                t = "";
                bracket = false;

            }
            else if(bracket) {
                t += s[i];
            }
            else
                ans += s[i];

        }
        return ans;
        
        
    }
};