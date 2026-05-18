class Solution {
private:
    
    void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<bool>>& v) {
        if(v[row][col])
            return;
        v[row][col] = true;
        if(row < heights.size() - 1 && heights[row + 1][col] >= heights[row][col])
            dfs(heights, row + 1, col, v);
        if(col < heights[0].size() - 1 && heights[row][col + 1] >= heights[row][col])
            dfs(heights, row, col + 1, v);
        if(row > 0 && heights[row - 1][col] >= heights[row][col])
            dfs(heights, row - 1, col, v);
        if(col > 0 && heights[row][col - 1] >= heights[row][col])
            dfs(heights, row, col - 1, v);

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), 0));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), 0));
        for(int i = 0; i < heights.size(); ++i) {
            dfs(heights, i, 0, pacific);
        }
        for(int j = 0; j < heights[0].size(); ++j) {
            dfs(heights, 0, j, pacific);
        }
        for(int i = 0; i < heights.size(); ++i) {
            dfs(heights, i, heights[0].size() - 1, atlantic);
        }
        for(int j = 0; j < heights[0].size(); ++j) {
            dfs(heights, heights.size() - 1, j, atlantic);
        }
        for(int i = 0; i < pacific.size(); ++i) {
            for(int j = 0; j < pacific[0].size(); ++j) {
                if(atlantic[i][j] == true && pacific[i][j] == true)
                    result.push_back(vector<int>({i, j}));
            }
        }
        return result;


        
    }
};
