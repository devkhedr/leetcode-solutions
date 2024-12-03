class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]] = max(mp[nums[i]], 1 + mp[nums[i] - 1]);
        }
        int mx = 0;
        for(int i=0;i<nums.size();i++) {
            mx = max(mx, mp[nums[i]]);
        }
        return mx;
    }
};