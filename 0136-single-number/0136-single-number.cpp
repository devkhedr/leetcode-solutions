class Solution {
public:
    int ans = 0, n;
    int singleNumber(vector<int>& nums) {
        n = nums.size();
        for(int i=0;i<n;i++) ans ^= nums[i];
        return ans;
    }
};