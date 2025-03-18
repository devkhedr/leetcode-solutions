class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(31, vector<int> (n+1));
        for(int i=1;i<=n;i++) {
            for(int x=0;x<=30;x++) {
                v[x][i] = v[x][i-1] + (bool)(nums[i-1] & (1 << x));
            }
        }
        int l = 1, r = 1, ans = 1;
        while(r <= n) {
            bool ok = 1;
            for(int x=0;x<=30;x++) {
                if((v[x][r] - v[x][l-1] )> 1) ok = 0;
            }
            if(ok) {
                ans = max(ans, r-l+1);
                r++;
            }
            else {
                l++;
            }
        }
        return ans;
    }
};