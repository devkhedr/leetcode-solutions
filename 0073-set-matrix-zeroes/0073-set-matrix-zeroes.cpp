class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ntf = 1, n = matrix.size(), m = matrix[0].size();
        for(int i=1;i<=5000;i++) {
            bool ok = 1;
            for(int j=0;j<n;j++) {
                for(int k=0;k<m;k++) {
                    if(matrix[j][k] == i) {
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok) {
                ntf = i;
                break;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == 0) {
                    for(int k=0;k<n;k++) {
                        if(matrix[k][j] != 0)
                            matrix[k][j] = ntf;
                    }
                    for(int k=0;k<m;k++) {
                        if(matrix[i][k]!=0)
                            matrix[i][k] = ntf;
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == ntf) matrix[i][j] = 0; 
            }
        }
    }
};