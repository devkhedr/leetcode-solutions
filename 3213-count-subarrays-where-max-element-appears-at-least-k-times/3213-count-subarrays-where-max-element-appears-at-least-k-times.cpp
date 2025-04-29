class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end()), l = 0, r = 0, cnt = 0;
        long long ans = 0;
        while(l < n) {
            while(r < n && cnt < k) {
                cnt += (nums[r] == mx);
                r++;
            }
            if(cnt >= k)ans += (n-r+1);
            cnt -= (nums[l] == mx);
            l++;
        }
        return ans;
    }
};