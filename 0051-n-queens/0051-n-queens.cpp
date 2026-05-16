class Solution {
private:
    unordered_set<int> col = {};
    unordered_set<int> up_diagonal = {};
    unordered_set<int> down_diagonal = {};
    void backtrack(vector<vector<string>>& result, vector<string>& board, int idx) {
        if(idx == board.size()) {
            result.push_back(board);
            return;
        }
        for(int i = 0; i < board[idx].size(); ++i) {
            // cout<<idx<<" "<<i<<endl;
            if(col.find(i) == col.end() && up_diagonal.find(i + idx) == up_diagonal.end() && down_diagonal.find(i - idx) == down_diagonal.end()) {
                board[idx][i] = 'Q';
                col.insert(i);
                up_diagonal.insert(i + idx);
                down_diagonal.insert(i - idx);
                backtrack(result, board, idx + 1);
                board[idx][i] = '.';
                col.erase(i);
                up_diagonal.erase(i + idx);
                down_diagonal.erase(i - idx);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        
        vector<string> board(n, string(n, '.'));
        
        backtrack(result, board, 0);
        return result;
    }
};
