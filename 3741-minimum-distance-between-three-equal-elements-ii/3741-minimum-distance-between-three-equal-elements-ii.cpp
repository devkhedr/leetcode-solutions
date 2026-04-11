class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n= nums.size();
        vector<int>idc[n+1];
        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            if(idc[nums[i]].size() <3)idc[nums[i]].push_back(i);
            else {
                idc[nums[i]][0] = idc[nums[i]][1];
                idc[nums[i]][1] = idc[nums[i]][2];
                idc[nums[i]][2] = i;
            }
            if(idc[nums[i]].size() == 3) {
                int x=idc[nums[i]][0], y = idc[nums[i]][1], z = idc[nums[i]][2];
                ans = min(ans, y-x+z-y+z-x);
            }
        }
        return (ans == INT_MAX?-1:ans);
    }
};