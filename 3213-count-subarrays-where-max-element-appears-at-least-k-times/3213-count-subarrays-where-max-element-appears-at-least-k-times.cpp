class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        long long l = 0, r = 0, ans = 0, cnt = 0;
        while(l < n) {
            while(r < n && cnt < k) {
                cnt += (nums[r] == mx);
                r++;
            }
            if(cnt >= k) {
                // cout << l << ' ' << r << '\n';
                ans += n-r+1;
            }
            cnt -= (nums[l] == mx);
            l++;
        }
        return ans;
    }
};