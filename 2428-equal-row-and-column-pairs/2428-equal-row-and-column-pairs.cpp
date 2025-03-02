class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> cntr, cntc;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++) {
            vector<int> v;
            for(int j=0;j<m;j++) {
                v.push_back(grid[i][j]);
            }
            cntr[v]++;
        }
        for(int i=0;i<m;i++) {
            vector<int>v;
            for(int j=0;j<n;j++) {
                v.push_back(grid[j][i]);
            }
            cntc[v]++;
        }
        int ans = 0;
        for(auto it: cntr) {
            ans += it.second * cntc[it.first];
        }
        return ans;
    }
};