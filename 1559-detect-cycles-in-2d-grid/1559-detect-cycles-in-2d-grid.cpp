class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<bool>> vis;
    bool found = 0;
    bool is_valid(int i, int j, int n, int m) {
        return i >= 0 && i< n && j>= 0 && j < m;
    } 
    void dfs(int &i, int &j, int &n, int &m, int p_i, int p_j, vector<vector<char>> &grid) {
        vis[i][j] = 1;
        for(int x=0;x<4;x++) {
            int xx = i + dx[x], yy = j + dy[x];
            if(is_valid(xx, yy, n, m) && grid[i][j] == grid[xx][yy]) {
                if(vis[xx][yy]) {
                    if(!(xx == p_i && yy == p_j))
                        found = 1;
                }
                else 
                    dfs(xx, yy, n, m, i, j, grid);
            }
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool> (m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j]) dfs(i, j, n, m, -1, -1, grid);
            }
        }
        return found;
    }
};