class Solution {
public:
    vector<vector<pair<int, int>>> decode = {
        {{0, 1}, {0, -1}}, {{1, 0}, {-1, 0}},  {{0, -1}, {1, 0}},
        {{1, 0}, {0, 1}},  {{-1, 0}, {0, -1}}, {{-1, 0}, {0, 1}}};
    bool isValid(int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return false;
        return true;
    }
    bool isEnterable(int nr, int nc, int r, int c, vector<vector<int>>& grid) {
        int val = grid[nr][nc] - 1;
        for (int i = 0; i < 2; i++) {
            if (r == nr + decode[val][i].first &&
                c == nc + decode[val][i].second)
                return true;
        }
        return false;
    }
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int m,
             int n) {
        queue<pair<int, int>> q;
        visited[0][0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int val = grid[r][c] - 1;
            for (int i = 0; i < 2; i++) {
                int nr = r + decode[val][i].first;
                int nc = c + decode[val][i].second;
                if (isValid(nr, nc, m, n) && isEnterable(nr, nc, r, c, grid) &&
                    !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        bfs(grid, visited, m, n);
        return visited[m - 1][n - 1];
    }
};