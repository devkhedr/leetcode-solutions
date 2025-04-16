class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, cntsubarr=0;
        long long ans = 0;
        map<int, int> mp;
        while(r < n) {
            cntsubarr += mp[nums[r]];
            mp[nums[r]]++;
            while(cntsubarr>=k) {
                ans += n-r;
                mp[nums[l]]--;
                cntsubarr -= mp[nums[l]];
                l++;
            }
            r++;
        }
        return ans;
    }
};