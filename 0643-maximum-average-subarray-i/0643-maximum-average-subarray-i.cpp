class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = k-1, n = nums.size();
        double ans = 0.0, sum = 0.0, mx = -2e9;
        for(int i=l;i<=r;i++) {
            sum += nums[i];
        } 
        while(r < n) {
            mx = max(mx, sum);
            r++;
            if(r < n) sum += nums[r];
            sum -= nums[l], l++;
        }
        return mx / k;
    }
};