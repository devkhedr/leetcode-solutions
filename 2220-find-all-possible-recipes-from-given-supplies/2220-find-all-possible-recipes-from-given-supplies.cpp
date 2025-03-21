class Solution {
public:
    map<string, bool> exist, can, vis;
    map<string, vector<string>> adj;
    void dfs(string u) {
        vis[u] = 1;
        bool ok = 1;
        for(string &v: adj[u]) {
            if(!vis[v]) {
                ok &= exist[v];
                dfs(v);
            }
        }
        if(ok && adj[u].size() > 0)can[u] = exist[u] = 1;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        
        for(int i=0;i<n;i++) {
            for(string &x: ingredients[i]) {
                adj[recipes[i]].push_back(x);
            }
        }
        for(string &x: supplies) {
            exist[x] = 1;
        }
        for(string &x: recipes) {
            if(!vis[x]) {
                dfs(x);
            }
        }
        vector<string> ans;
        for(string &x: recipes) {
            if(can[x]) ans.push_back(x);
        }
        return ans;
    }
};