class Solution {
public:
    int n;
    int dp[100002][2];
    int solve(int i, int bought, vector<int>& prices) {
        if(i >= n) return 0;
        int &ret = dp[i][bought];
        if(~ret) return ret;
        ret = solve(i+1, bought, prices);
        if(bought) ret = max(ret , prices[i] + solve(i+1, 0, prices));
        else ret = max(ret ,solve(i+1, 1, prices) - prices[i]);
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, prices);
    }
};