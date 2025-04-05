class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int mask = 0; mask < (1LL<<n); mask++) {
            int xoor = 0;
            for(int i=0;i<n;i++) {
                if(mask & (1LL << i)) xoor ^= nums[i];
            }
            ans += xoor;
        }
        return ans;
    }
};