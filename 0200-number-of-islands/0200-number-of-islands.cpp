class Solution {
private:
    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';
        while(q.size()) {
            auto t = q.front();
            int i = t.first;
            int j = t.second;
            // cout<<i<<" "<<j<<endl;
            q.pop();
            if(i > 0 && grid[i-1][j] == '1') {
                q.push({i-1, j});
                grid[i-1][j] = '0';
                
            }
                
            if(i < grid.size() - 1 && grid[i+1][j] == '1') {
                q.push({i+1, j});
                grid[i+1][j] = '0';
            }
                
            if(j > 0 && grid[i][j-1] == '1') {
                q.push({i, j-1});
                grid[i][j-1] = '0';
            }   
                
            if(j < (grid[0].size() - 1) && grid[i][j+1] == '1') {
                 q.push({i, j+1});
                 grid[i][j + 1] = '0';

            }
               
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0; i < m; ++i ) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    // cout<<"bfs"<<endl;
                    bfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
};