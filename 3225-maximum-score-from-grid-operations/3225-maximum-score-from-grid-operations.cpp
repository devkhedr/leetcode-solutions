class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        const int MAX_SIZE = 109;
        const long long INF = LLONG_MAX;

        vector<vector<long long>> dp(MAX_SIZE, vector<long long>(MAX_SIZE, -INF)); 
        vector<vector<long long>> maxPrefix(MAX_SIZE, vector<long long>(MAX_SIZE, 0)); 
        vector<vector<long long>> maxSuffix(MAX_SIZE, vector<long long>(MAX_SIZE, 0));
        vector<long long> prefixSum(MAX_SIZE, 0);

        int n = grid.size();
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = -INF; 
            }
        }

        for (int col = 0; col < n; ++col) {
            prefixSum[0] = 0;
            for (int row = 1; row <= n; ++row) {
                prefixSum[row] = prefixSum[row - 1] + grid[row - 1][col];
            }

            for (int row = 0; row <= n; ++row) {
                maxPrefix[row][0] = dp[row][0];
                for (int k = 1; k <= n; ++k) {
                    maxPrefix[row][k] = max(maxPrefix[row][k - 1], dp[row][k]);
                }
                maxSuffix[row][n + 1] = 0;
                for (int k = n; k >= 0; --k) {
                    maxSuffix[row][k] = max(maxSuffix[row][k + 1], dp[row][k] + (row < k ? prefixSum[k] - prefixSum[row] : 0));
                }
            }

            for (int row = 0; row <= n; ++row) {
                for (int k = 0; k <= n; ++k) {
                    dp[row][k] = max(maxPrefix[k][row] + (k < row ? prefixSum[row] - prefixSum[k] : 0), maxSuffix[k][row + 1]);
                }
            }
        }

        long long maxScore = -INF;
        for (int i = 0; i <= n; ++i) {
            maxScore = max(maxScore, dp[0][i]);
        }

        return maxScore;
    }
};