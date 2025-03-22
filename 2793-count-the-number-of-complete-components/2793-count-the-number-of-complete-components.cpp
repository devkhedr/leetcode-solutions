class Solution {
public:
    int cntN, cntE;
    vector<vector<int>> adj;
    vector<bool> vis;
    void dfs(int u) {
        vis[u] = 1;
        cntN++;
        cntE += (adj[u].size());
        for(int &x: adj[u]) {
            if(!vis[x]) {
                dfs(x);
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
                dfs(i);
                ans += ((cntN*(cntN-1) / 2) == (cntE / 2));
            }
        }
        return ans;
    }
};