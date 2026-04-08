class Solution {
public:
    const int MOD = 1e9 + 7;
    int mult(int &a, int &b) {
        return ((1LL*a%MOD)*(b%MOD))%MOD;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &x: queries) {
            int i = x[0], j = x[1];
            while(i <= j) {
                nums[i] = mult(nums[i], x[3]);
                i += x[2];
            }
        }
        int ans = 0;
        for(int &x: nums) ans ^= x;
        return ans;
    }
};
/*
q = 0 2 1 4
from 0 to 2
0 += 1, 1 += 1
nums[0]*=4
nums[1]*=4
nums[2]*=4
*/