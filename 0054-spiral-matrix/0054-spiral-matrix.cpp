class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        int i =0, j = 0, x = 0, y = 1;
        vector<vector<bool>> vis(n, vector<bool> (m));
        while(ans.size() < m*n) {
            if(i == n || j == m || i == -1 || j == -1 ||vis[i][j]) {
                i -= x, j -= y;
                x^=y, y^=x,x^=y;
                if(!x)y=-y;
                i+=x,j+=y;
            } else {
                ans.push_back(matrix[i][j]);
                vis[i][j] = 1;
                i+=x, j+=y;
            }
        }
        return ans;
    }
};