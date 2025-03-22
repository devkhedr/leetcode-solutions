class Solution {
public:
    int cntN, cntE;
    vector<vector<int>> adj;
    vector<bool> vis;
    queue<int> q;
    void bfs(int i) {
        q.push(i);
        vis[i] = 1;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            cntN++;
            cntE += adj[x].size();
            for(auto &u: adj[x]) {
                if(!vis[u]) {
                    q.push(u), vis[u] = 1;
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        adj.resize(n), vis.resize(n);
        for(auto &it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                cntN = cntE = 0;
                bfs(i);
                ans += ((cntN*(cntN-1) / 2) == (cntE / 2));
            }
        }
        return ans;
    }
};