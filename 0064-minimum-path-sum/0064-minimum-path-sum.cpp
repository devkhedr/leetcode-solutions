class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[n][m];
        dp[n-1][m-1] = grid[n-1][m-1];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1&&j==m-1)continue;
                dp[i][j] = 1000000000;
                if(i+1<n)dp[i][j] = min(dp[i][j], dp[i+1][j]+grid[i][j]);
                if(j+1<m)dp[i][j] = min(dp[i][j], dp[i][j+1]+grid[i][j]);
            }
        }
        
        return dp[0][0];
    }
};