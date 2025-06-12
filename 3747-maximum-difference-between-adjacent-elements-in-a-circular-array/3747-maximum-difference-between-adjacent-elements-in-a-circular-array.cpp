class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int i=0;i<n;i++) {
            mx = max(mx, abs(nums[i] - nums[(i+1)%n]));
        }
        return mx;
    }
};