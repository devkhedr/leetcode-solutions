class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int &i: nums) {
            if(i <0)  i=-i;
        } 
        int idx = -1, mn = INT_MAX, n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] < mn) {
                mn = nums[i], idx = i;
            }
        }
        int l = idx, r = idx+1;
        while(l >= 0 && r<n) {
            if(nums[l] <= nums[r])ans.push_back(nums[l]*nums[l]), l--;
            else ans.push_back(nums[r]*nums[r]), r++;
        }
        while(l >= 0) ans.push_back(nums[l]*nums[l]), l--;
        while(r < n) ans.push_back(nums[r]*nums[r]), r++;
        return ans;
    }
};