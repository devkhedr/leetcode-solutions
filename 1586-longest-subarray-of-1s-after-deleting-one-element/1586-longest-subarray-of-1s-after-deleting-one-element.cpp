class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), cnt0 = 0, cnt1 = 0, mx = 0;
        while(l < n) {
            while(r < n && cnt0<=1) {
                if(nums[r] == 0) cnt0++;
                else cnt1++;
                if(cnt0 <= 1) {
                    if(cnt1 == n) mx = max(cnt1-1, mx);
                    else mx = max(cnt1, mx);
                }
                r++;
            }
            if(cnt0 <= 1) {
                if(cnt1 == n) mx = max(cnt1-1, mx);
                else mx = max(cnt1, mx);
            }
            if(nums[l] == 1) cnt1--;
            else cnt0--;
            l++;
        }
        return mx;
    }
};