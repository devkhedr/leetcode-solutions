class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, mx = 0, n = nums.size();
        int cnt0 = 0, cnt1 = 0;
        while(l < n) {
            while(r < n && cnt0<=k) {
                if(nums[r] == 0) cnt0++;
                else cnt1++;
                r++;
                if(cnt0<=k) mx = max(mx, r-l);
            }
            if(cnt0<=k) mx = max(mx, r-l);
            if(nums[l] == 0) cnt0--;
            else cnt1--;
            l++;
        }
        return mx;
    }
};