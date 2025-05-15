class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = -1e4, mx_so_far = -1e4;
        for(int &x: nums) {
            mx = max(x, mx + x);
            mx_so_far = max(mx, mx_so_far);
        }
        return mx_so_far;
    }
};