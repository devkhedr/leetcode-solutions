class Solution {
public:
    int tribonacci(int n) {
        vector<int> ans(38);
        ans[0] = 0, ans[1] = 1, ans[2] = 1;
        int sum = 0;
        for(int i=3;i<=37;i++) ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
        return ans[n];
    }
};