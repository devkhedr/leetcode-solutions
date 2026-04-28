class Solution {
public:
    int cost(vector<int> &arr, int &x, int &target) {
        int ret = 0, dif = 0;
        for(int &y: arr) {
            dif = abs(y - target);
            if((dif % x) == 0) ret += dif / x;
            else return INT_MAX; 
        }
        return ret;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        vector<int> v;
        for(int i = 0; i< n;i++) {
            for(int j=0;j<m;j++) {
                v.push_back(grid[i][j]);
            }
        }
        n *= m;
        sort(v.begin(), v.end());
        int ans = cost(v, x, v[n/2]);
        if(n%2 == 0) ans = min(ans, cost(v, x, v[n/2-1]));
        if(ans == INT_MAX) return -1;
        return ans;
    }
};