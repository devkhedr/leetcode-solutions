class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> max_list;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        pq.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;
        int current_max = 0;
        
        while (!pq.empty()) {
            auto [val, x, y] = pq.top();
            pq.pop();
            current_max = max(current_max, val);
            max_list.push_back(current_max);
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.emplace(grid[nx][ny], nx, ny);
                }
            }
        }
        vector<int> ans;
        for (int q : queries) {
            auto it = upper_bound(max_list.begin(), max_list.end(), q - 1);
            ans.push_back(it - max_list.begin());
        }
        
        return ans;
    }
};