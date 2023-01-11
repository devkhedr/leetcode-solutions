// Author: Mohamed Khedr
class Solution {
public:
    /*
    - this a simple recursive approach: just by trying all the different paths
    we took the current element in the current row and add it to the minimum between the two choices:
    either element in index j or index j + 1 on the next row.
    - and by adding memoization technique-> the time complexity become O(N^2).
    */
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>> &triangle) {
        if (i == triangle.size())
            return 0;
        int &ret = dp[i][j];
        if (~ret)
            return ret;
        return ret = triangle[i][j] + min(solve(i + 1, j, triangle), solve(i + 1, j + 1, triangle));
    }
    int minimumTotal(vector<vector<int>> &triangle) {
        dp = vector<vector<int>>(200, vector<int>(200, -1));
        return solve(0, 0, triangle);
    }
};
