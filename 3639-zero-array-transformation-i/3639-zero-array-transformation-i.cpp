class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> p(n+3);
        for(auto &it: queries) {
            p[it[0]+1] -= 1;
            p[it[1] + 2] += 1;
        }
        bool ok = 1;
        for(int i=1;i<=n;i++) {
            p[i] += p[i-1];
        }
        for(int i=1;i<=n;i++) {
            p[i]+=nums[i-1];
            ok &= (p[i] <= 0);
        }
        return ok;
    }
};