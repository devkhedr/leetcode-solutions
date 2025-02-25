class Solution {
public:
    vector<vector<int>> ans;
    int dp[35][35];
    int solve(int i, int j) {
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0 || i<j) return 0;
        int &ret = dp[i][j];
        if(~ret) return ret;
        ret = solve(i-1,j-1) + solve(i-1, j);
        return ret;
    }
    vector<vector<int>> generate(int numRows) {
        ans = vector<vector<int>> (numRows);
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<numRows;i++) {
            ans[i] = vector<int>(i+1);
            for(int j=0;j<i+1;j++) {
                ans[i][j] = solve(i, j);
            }
        }
        return ans;
    }
};