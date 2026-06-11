class Solution {
public:
    int d;

    void dfs(int u, int p, int h, vector<vector<int>> &g) {
        d = max(d, h);
        for (int v :g[u]) {
            if (v!= p) {
                dfs(v,u,h+1,g);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& e) {
        
        int n=e.size()+1;
        d=0;

        vector<vector<int>>g(n+1);

        for (auto x :e) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }

        dfs(1,0,0,g);

        long long r=1;
        long long m=1000000007;
        for (int i=0; i<d-1;i++) {
            r =(r*2)%m;
        }

        return r;
    }
};