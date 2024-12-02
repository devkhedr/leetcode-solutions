class Solution {
public:
    int dp[10000];
    int solve(int i, vector<int>& nums) {
        if(i == nums.size() - 1)return 0;
        int &ret = dp[i];
        if(~ret) return ret;
        ret = 1000000;
        for(int j=0;j<=nums[i];j++) {
            if(j + i < nums.size())
                ret = min(ret, 1 + solve(j + i, nums));
        }
        return ret;
    }
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }
};