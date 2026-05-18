class Solution {
private:
    bool cycle(unordered_map<int, unordered_set<int>>& m, int val, unordered_set<int>& s,  vector<bool>& v) {
        if(s.count(val))
            return true;
        for(auto x: m[val]) {
            if(v[x])
                continue;
            s.insert(val);
            if(cycle(m, x, s, v))
                return true;
            s.erase(val);
        }
        v[val] = true;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> m;
        vector<bool> v(numCourses, false);
        for(auto x: prerequisites) {
            m[x[0]].insert(x[1]);
        }
        for(auto x: m) {
            unordered_set<int> s;
            if(cycle(m, x.first, s, v))
                return false;
        }
        return true;

    }
};
