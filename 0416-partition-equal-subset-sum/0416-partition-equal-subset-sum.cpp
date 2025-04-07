class Solution {
public:
    int dp[200][20001];
    int solve(int i, int sum, int &n, vector<int> &nums) {
        if (i == n) return sum == 0;
        if (dp[i][sum] != -1) return dp[i][sum];
        
        int &ret = dp[i][sum];
        ret = solve(i+1, sum, n, nums);
        if (sum - nums[i] >= 0)
            ret = max(ret, solve(i+1, sum - nums[i], n, nums));
        return ret;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(0, sum / 2, n, nums);
    }
};