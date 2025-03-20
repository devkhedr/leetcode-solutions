struct DSU {
    int n;
    vector<int> parent, gsize, band;   
    DSU(int n) {
        this->n = n;
        parent.resize(n+1);
        gsize.resize(n+1, 1);
        band.resize(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void merge(int x, int y, int val) {
        x = find(x);
        y = find(y);
        if(x == y) {
            band[x] &= val;
            return;
        }
        if(gsize[x] < gsize[y]) swap(x, y);
        parent[y] = x;
        gsize[x] += gsize[y];
        band[x] &= (val & band[y]);
    }
    int getSize(int x) {
        return gsize[find(x)];
    }
    int getAnd(int x) {
        return band[find(x)];
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU s(n);
        for(auto &it: edges) {
            s.merge(it[0], it[1], it[2]);
        }
        vector<int> ans;
        for(auto &it: query) {
            int x = s.find(it[0]), y = s.find(it[1]);
            if(x!=y) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(s.getAnd(x));
            }
        }
        return ans;
    }
};