class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]=i;
        for(int i=0;i<n;i++) {
            if(mp[target-nums[i]] && i!=mp[target-nums[i]]) return {i, mp[target-nums[i]]};
        }
        return {-1,-1}; 
    }
};