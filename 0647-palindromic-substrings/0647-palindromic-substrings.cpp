class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        // cout<<"hello";
        for(int i = 0; i < s.size(); ++i) {
            ++count;
            int low = i - 1;
            int high = i + 1;
            // cout<<low<<" "<<high<<endl;
            while(low >= 0 && high < s.size() && s[low] == s[high]) {
                --low;
                ++high;
                ++count;
                // cout<<count<<endl;
            }
        }
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == s[i + 1]) {
                ++count;
                // cout<<count<<endl;
                int low = i - 1;
                int high = i + 2;
                while(low >= 0 && high < s.size() && s[low] == s[high]) {
                    --low;
                    ++high;
                    ++count;
                    // cout<<count;
                }
            }
        }
        return count;
    }
};