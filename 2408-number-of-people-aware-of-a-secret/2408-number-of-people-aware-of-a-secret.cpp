class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        for (int day = 2; day <= n; day++) {
            for (int i = max(1, day - forget + 1);i <= min(day - delay, n); i++) {
                dp[day] = (dp[day] + dp[i]) % MOD;
            }
        }
        long long result = 0;
        for (int day = max(1, n - forget + 1); day <= n; day++) {
            result = (result + dp[day]) % MOD;
        }
        
        return result;
    }
};