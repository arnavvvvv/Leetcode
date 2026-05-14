struct Comparator {
    bool operator()(pair<char, int>& lhs, pair<char, int>& rhs) {
        return lhs.second < rhs.second;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 1;
        int k = tasks.size();
        unordered_map<char, int> m;
        queue<pair<char, int>> q;
        for(char x: tasks)
            ++m[x];
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comparator> max_heap(begin(m), end(m));
        while(k) {
            // cout<<"time "<<time<<endl;
            if(max_heap.size()) {
                pair<char, int> t = max_heap.top();
                // cout<<t.first<<" "<<t.second<<endl;
                max_heap.pop();
                --m[t.first];
                q.push(pair<char, int>(t.first, time + n));
                --k;
            }
            if(q.size() && time == q.front().second) {
                char c = q.front().first;
                q.pop();
                if(m[c] > 0) {
                    max_heap.push(pair<char, int>(c, m[c]));
                } 
            }
             ++time;

        }
        return time - 1;
        
    }
};
