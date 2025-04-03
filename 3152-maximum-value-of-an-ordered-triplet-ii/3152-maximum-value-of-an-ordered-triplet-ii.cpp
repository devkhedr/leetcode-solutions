class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n), s(n);
        p[0] = nums[0], s[n-1] = nums[n-1];
        for(int i=1;i<n;i++) p[i] = max(p[i-1], nums[i]);
        for(int i=n-2;i>=0;i--) s[i] = max(s[i+1], nums[i]);
        long long ans = 0;
        for(int i=1;i<n-1;i++) ans = max(ans, (long long)(p[i-1]-nums[i])*s[i+1]);
        return ans;
    }
};