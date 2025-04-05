class Solution {
public:
    int n;
    int solve(int i, int xoor, vector<int> &nums) {
        if(i == n) return xoor;
        int ret = solve(i+1, xoor, nums);
        ret += solve(i+1, xoor^nums[i], nums);
        return ret;
    }
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        return solve(0, 0, nums);
    }
};