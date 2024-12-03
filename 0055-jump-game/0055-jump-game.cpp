class Solution {
public:
    int mx = 1;
    bool canJump(vector<int>& nums) {
        int mx = 1;
        for(int i=1;i<=nums.size();i++) {
            if(i > mx) return 0;
            mx = max(mx, nums[i-1] + i);
        }
        return 1;
    }
};