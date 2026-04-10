class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    if(nums[i] == nums[j] and nums[i] == nums[k]) {
                        ans= min(ans, j-i+k-j+k-i);
                    }
                }
            }
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};