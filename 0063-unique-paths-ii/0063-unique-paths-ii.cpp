class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m));
        dp[n-1][m-1] = !obstacleGrid[n-1][m-1];
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(obstacleGrid[i][j] == 1) continue;
                if(i+1 < n)dp[i][j] += dp[i+1][j];
                if(j+1 < m)dp[i][j] += dp[i][j+1]; 
            }
        }
        return (int)dp[0][0];
    }
};