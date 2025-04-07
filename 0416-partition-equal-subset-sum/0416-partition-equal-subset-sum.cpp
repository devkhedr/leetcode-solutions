class Solution {
public:
    int dp[201][20001];
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        sum /= 2;
        int n = nums.size();
        dp[n][0] = 1;
        for(int i=n-1;i>=0;i--) {
            for(int x=0;x<=sum;x++) {
                dp[i][x] = dp[i+1][x];
                if(x >= nums[i])
                    dp[i][x] = max(dp[i][x], dp[i+1][x-nums[i]]);
            }
        }
        return dp[0][sum];
    }
};