class Solution {
public:
    int dp[27][27][400];
    int calc(int x, int y) {
        if(y == 26) return 0;
        int x1 = x / 6, y1 =x %6, x2 = y/6, y2 = y%6;
        return abs(x1-x2) + abs(y1-y2);
    }
    int solve(int left, int right, string &s, int idx) {
        if(idx == s.size()) return 0;
        int &ans = dp[left][right][idx];
        if(~ans) return ans;
        int cur = s[idx]-'A';
        int option1 = calc(cur, left) + solve(cur, right, s, idx+1);
        int option2 = calc(cur, right) + solve(left, cur, s, idx+1);
        return ans = min(option1, option2);
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(26, 26, word, 0);
    }
};