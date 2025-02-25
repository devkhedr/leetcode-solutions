class Solution {
public:
    int n,m;
    bool isValid(int i, int j) {
        return (i >= 0 && j>=0 && i < n && j < m);
    }
    vector<vector<bool>> vis;
    int solve(int i, int j, vector<vector<int>>&grid) {
        if(!isValid(i, j) || !grid[i][j] || vis[i][j]) return 0;
        vis[i][j] = 1;
        int ret = grid[i][j];
        ret += solve(i+1, j, grid);
        ret += solve(i, j+1, grid);
        ret += solve(i-1, j, grid);
        ret += solve(i, j-1, grid);
        return ret;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>> (n, vector<bool>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans = max(ans, solve(i, j, grid));
            }
        }
        return ans;
    }
};