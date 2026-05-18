class Solution {
private:
    bool dfs(vector<vector<int>>& adj, int idx, vector<int>& visited, stack<int>& st) {
        if(visited[idx] == 2)
            return true;
        if(visited[idx] == 1)
            return false;
        visited[idx] = 1;
        for(int i = 0; i < adj[idx].size(); ++i) {
            if(!dfs(adj, adj[idx][i], visited, st))
                return false;
        }
        st.push(idx);
        visited[idx] = 2;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        stack<int> st;
        vector<int> visited(numCourses, 0);
        vector<int> result;
        for(auto x: prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(!dfs(adj, i, visited, st))
                return vector<int>();
        }
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
        
        
    }
};
