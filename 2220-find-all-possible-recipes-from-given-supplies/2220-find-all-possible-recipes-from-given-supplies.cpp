class Solution {
public:
    map<string, bool> exist, can, vis;
    map<string, vector<string>> adj;
    stack<string> topo;
    void dfs(string u) {
        vis[u] = 1;
        for(string &v: adj[u]) {
            if(!vis[v]) {
                dfs(v);
            }
        }
        topo.push(u);
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
        vector<string> topol;
        while(!topo.empty()) {
            topol.push_back(topo.top());
            topo.pop();
        }
        reverse(topol.begin(), topol.end());
        for(auto &it: topol) cout << it << ' ' ;
        cout << '\n';
        for(string &x: topol) {
            bool ok = 1;
            for(string &it: adj[x]) {
                ok &= exist[it];
            }
            if(ok and adj[x].size() > 0)exist[x] = 1, can[x] = 1;
        }
        vector<string> ans;
        for(string &x: recipes) {
            if(can[x]) ans.push_back(x);
        }
        return ans;
    }
};