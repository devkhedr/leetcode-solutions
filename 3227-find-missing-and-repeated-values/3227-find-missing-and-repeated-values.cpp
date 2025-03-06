class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> f(n*n+1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                f[grid[i][j]]++;
            }
        } 
        vector<int> res(2);
        for(int i=1;i<=n*n;i++) {
            if(!f[i]) res[1] = i;
            if(f[i] == 2) res[0] = i;
        }
        return res;
    }
};