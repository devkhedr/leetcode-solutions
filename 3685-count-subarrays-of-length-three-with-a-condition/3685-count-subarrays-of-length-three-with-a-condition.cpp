class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i=0;i<n-2;i++) {
            if(nums[i+1] & 1) continue;
            if(nums[i] + nums[i+2] == (nums[i+1]/2)) ans++;
        }
        return ans;
    }
};