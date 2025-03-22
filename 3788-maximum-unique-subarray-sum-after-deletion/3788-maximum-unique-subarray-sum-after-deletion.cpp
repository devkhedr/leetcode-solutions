class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = max(0, nums[0]);
        for(int i=1;i<n;i++) {
            if(nums[i] != nums[i-1]) {
                sum = max(sum, sum + nums[i]);
            }
        }
        if(sum == 0 && nums[0]<0 && nums.back() < 0) return nums.back();
        return sum;
    }
};