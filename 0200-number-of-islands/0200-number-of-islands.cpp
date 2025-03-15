class Solution {
public:
    bool vis[301][301];
    int n, m, cnt = 0;
    bool isValid(int i, int j) {
        return (i>=0 && i < n && j >= 0 && j < m);
    }
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if(!isValid(i, j) || vis[i][j] || grid[i][j] == '0') return;
        vis[i][j] = 1;
        dfs(i+1, j, grid);
        dfs(i, j+1, grid);
        dfs(i-1, j, grid);
        dfs(i, j -1, grid); 
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    cnt++, dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};