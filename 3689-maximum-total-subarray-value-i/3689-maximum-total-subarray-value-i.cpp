class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx = INT_MIN, mn = INT_MAX;
        for(int x: nums) {
            mn = min(mn, x), mx = max(mx, x);
        }
        return 1LL * k * (mx-mn);
    }
};