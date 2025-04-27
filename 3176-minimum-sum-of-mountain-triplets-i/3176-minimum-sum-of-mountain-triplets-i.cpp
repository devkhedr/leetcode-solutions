class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n+1), s(n+3);
        p[0] = s[n+1] = INT_MAX;
        for(int i=1;i<=n;i++) {
            p[i] = min(p[i-1], nums[i-1]);
        }
        for(int i=n;i>=1;i--) {
            s[i] = min(s[i+1], nums[i-1]);
        }
        int ans = INT_MAX;
        for(int i=2;i<n;i++) {
            if(p[i-1] < nums[i-1] and s[i+1] < nums[i-1]) {
                ans = min(ans, p[i-1] + nums[i-1] + s[i+1]);
            }
        }
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};