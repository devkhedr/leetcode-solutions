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
        auto check = [&](int mid) {
            int l = 1, r = mid;
            while(r<=n) {
                bool ok = 1;
                for(int x=0;x<=30;x++) {
                    if((v[x][r] - v[x][l-1] )> 1) ok = 0;
                }
                if(ok) return 1;
                l++, r++;
            }
            return 0;
        };
        int low = 1, high = n, sol = 1, mid;
        while(low <= high) {
            mid = low + (high - low) /2;
            if(check(mid)) sol = mid, low = mid + 1;
            else high = mid - 1;
        }
        return sol;
    }
};