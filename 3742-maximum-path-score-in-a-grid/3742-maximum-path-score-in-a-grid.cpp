class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;
    int fn(int i, int j, vector<vector<int>> & grid, int k)
    {
        if(i>=m || j>=n)
        return INT_MIN;
        if(k<1 && grid[i][j]>0)
        return INT_MIN;

        if(i==m-1 && j==n-1)
        return grid[i][j];
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        int cost = grid[i][j] == 0?0 : 1;
        int d = fn(i+1,j,grid,k-cost);
        int r = fn(i,j+1,grid,k-cost);
        int mx = max(d,r);
        if(mx == INT_MIN)
        return dp[i][j][k]=INT_MIN;
        
        return dp[i][j][k]=grid[i][j]+mx;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans = fn(0,0,grid,k);
        return ans == INT_MIN?-1:ans;
    }
};