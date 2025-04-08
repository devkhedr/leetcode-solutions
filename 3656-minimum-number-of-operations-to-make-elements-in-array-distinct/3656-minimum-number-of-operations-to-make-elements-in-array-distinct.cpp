class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> vis(101);
        int idx = -1, n = nums.size();
        for(int i=n-1;i>=0;i--) {
            if(vis[nums[i]]) {
                idx  = i;
                break;
            }
            vis[nums[i]] = 1;
        }
        return (idx + 3) / 3;
    }
};