class Solution {
public:
    const int MOD = 12345;
    int mult(int &x, int &y) {
        return ((x%MOD) * (y%MOD))%MOD;
    }
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        int suf = 1, pref = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans[i][j] = pref;
                pref = mult(pref, grid[i][j]);
            }
        }
        for(int i=n-1;i>-1;i--) {
            for(int j=m-1;j>-1;j--) {
                ans[i][j] = mult(ans[i][j], suf);
                suf = mult(suf, grid[i][j]);
            }
        }
        return ans;
    }
};