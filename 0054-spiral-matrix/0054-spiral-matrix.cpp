class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int right = 0;
        int left = matrix.size() - 1;
        int up = 0;
        int down = matrix[0].size() - 1;
        int count = 0;
        vector<int> result;
        while(count <= m * n) {
            for(int i = up; i < n; ++i) {
                if(matrix[right][i] == 101)
                    break;
                result.push_back(matrix[right][i]);
                matrix[right][i] = 101;
                ++count;
            }
            ++right;
            if( count == m * n)
                break;
            for(int i = right; i < matrix.size(); ++i) {
                if(matrix[i][down] == 101)
                    break;
                result.push_back(matrix[i][down]);
                matrix[i][down] = 101;
                ++count;
            }
            --down;
             if( count == m * n)
                break;
            for(int i = down; i >= 0; --i) {
                if(matrix[left][i] == 101)
                    break;
                result.push_back(matrix[left][i]);
                matrix[left][i] = 101;
                ++count;
            }
            --left;
             if( count == m * n)
                break;
            for(int i = left; i >= 0; --i) {
                if(matrix[i][up] == 101)
                    break;
                result.push_back(matrix[i][up]);
                matrix[i][up] = 101;
                ++count;
            }
            ++up;
             if( count == m * n)
                break;

        }

        return result;

        
    }
};
