class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0, n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            ans[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        for(int i=n-1;i>=0;i--) {
            ans[i] -= sum, ans[i] = abs(ans[i]);
            sum += nums[i];
        }
        return ans;
    }
};