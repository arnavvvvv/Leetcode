typedef pair<char, int> ci;
struct Comparator{
    bool operator()(const ci& lhs, const ci& rhs) {
        return lhs.second < rhs.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        char temp = ' ';
        int n = s.size();
        string ans = "";
        for(char x: s)
            ++m[x];
        priority_queue<ci, vector<ci>, Comparator> max_heap(begin(m), end(m));
        while(n && max_heap.size()) {
            //cout<<max_heap.top().first<<" "<<max_heap.top().second<<endl;
            char x = max_heap.top().first;
            max_heap.pop();
            ans += x;
            --m[x];
            if(temp != ' ' && m[temp])
                max_heap.push(ci(temp, m[temp]));
            temp = x;
            --n;

        }
        if(n == 0)
            return ans;
        return "";



    }
};