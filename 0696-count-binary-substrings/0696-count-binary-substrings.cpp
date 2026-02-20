class Solution {
public:
    int countBinarySubstrings(string s) {
        int count_0 = 0;
        int count_1 = 0;
        int total_count = 0;
        int flow = -1;
        for(int i = 0; i < s.size();) {
            while(i < s.size() && s[i] == '1') {
                if(count_0) {
                    ++total_count;
                    --count_0;
                }
                ++count_1;
                ++i;
                flow = 1;
                // cout<<total_count<<" "<<count_0<<" "<<count_1<<" "<<i<<endl;
            }
            if(flow == 1) {
                count_0 = 0;
                flow = -1;
                continue;
            }
                
            while(i < s.size() && s[i] == '0') {
                if(count_1) {
                    ++total_count;
                    --count_1;
                }
                ++count_0;
                ++i;
                flow = 0;
                // cout<<"Inside 0 "<<total_count<<" "<<count_0<<" "<<count_1<<" "<<i<<endl;
            }
            if(flow == 0) {
                count_1 = 0;
                flow = -1;
                continue;
            }
        }
        return total_count;
    }
};