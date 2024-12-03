class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        for(int mask = 0; mask < (1<<n); mask++) {
            vector<int> cont;
            for(int i=0;i<n;i++) {
                if(mask&(1<<i)) {
                    cont.push_back(nums[i]);
                }
            }
            ret.push_back(cont);
        }
        return ret;
    }
};