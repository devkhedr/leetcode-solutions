class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2);
        dp[n] = 0, dp[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--) {
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        } 
        return dp[0];
    }
};