class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;
        // Check first row and column for zeros
        for (int i = 0; i < m; ++i) if (matrix[i][0] == 0) firstCol = true;
        for (int j = 0; j < n; ++j) if (matrix[0][j] == 0) firstRow = true;
        // Mark zeros in first row/col
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        // Zero cells based on marks
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        // Zero first row/col if needed
        if (firstRow) for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        if (firstCol) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
};