class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // u can find the maximum betwween max subarray sum and abs(min subarray sum)
        int n = nums.size();
        int ans = -10000000, max_ending_here = -10000000;
        for(int i=0;i<n;i++) {
            max_ending_here = max(max_ending_here + nums[i], nums[i]);
            ans = max(ans, max_ending_here);
        }    

        int ans1 = 1000000, min_ending_here = 1000000;
        for(int i=0;i<n;i++) {
            min_ending_here = min(min_ending_here + nums[i], nums[i]);
            ans1 = min(ans1, min_ending_here);
        }
        return max(abs(ans), abs(ans1));
    }
};