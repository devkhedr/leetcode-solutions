class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& triangle) {
        if(i == triangle.size()) return 0;
        int &ret = dp[i][j];
        if(~ret) return ret;
        return ret = triangle[i][j] + min(solve(i+1, j, triangle), solve(i+1,j+1, triangle));
    } 
    int minimumTotal(vector<vector<int>>& triangle) {
        dp = vector<vector<int>> (300, vector<int>(300, -1));
        return solve(0,0, triangle);
    }
};