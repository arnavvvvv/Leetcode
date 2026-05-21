class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int top = 0;
        int left = 0;
        for(int i = 0; i < matrix[0].size(); ++i) {
            if(matrix[0][i] == 0)
                top = 1;
        }
        for(int i = 0; i < matrix.size(); ++i) {
            if(matrix[i][0] == 0)
                left = 1;
        }
        for(int i =  1; i < matrix.size(); ++i) {
            for(int j = 1; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0; matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); ++i) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < matrix[0].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < matrix[0].size(); ++j) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(top) {
            for(int j = 0; j < matrix[0].size(); ++j)
                matrix[0][j] = 0;
        }
        if(left) {
            for(int i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
        }
        

        
    }
};
