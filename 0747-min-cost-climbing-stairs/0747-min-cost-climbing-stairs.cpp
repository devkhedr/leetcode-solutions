class Solution {
public:
    int dp[1050];
    int minCostClimbingStairs(vector<int>& cost) {        
        for(int i=cost.size()-1;i>=0;i--) {
            dp[i] = min(dp[i+1], dp[i+2]) + cost[i];
        }
        return min(dp[0], dp[1]);
    }
};