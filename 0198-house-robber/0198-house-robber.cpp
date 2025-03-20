class Solution {
public:
    int dp[101];
    int solve(int i, vector<int> &nums) {
        if(i >= nums.size()) return 0;
        int &ret = dp[i];
        if(~ret) return ret;
        ret = solve(i+1, nums);
        ret = max(ret, solve(i+2, nums) + nums[i]);
        return ret;
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }
};