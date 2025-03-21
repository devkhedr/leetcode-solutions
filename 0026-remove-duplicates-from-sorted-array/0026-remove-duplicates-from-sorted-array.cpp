class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans(nums.size());
        int k = 0;
        map<int, int> vis;
        for(int i: nums) {
            if(!vis[i]) ans[k] = i, k++;
            vis[i] = 1;
        }
        for(int i=0;i<ans.size();i++) {
            nums[i] = ans[i];
        }
        return k;
    }
};