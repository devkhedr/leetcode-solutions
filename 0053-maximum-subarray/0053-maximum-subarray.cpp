class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, mx = INT_MIN;
        for(int i: nums)
        {
            cur+=i;
            mx = max(mx, cur);
            if(cur<0) cur = 0;
        }
        return mx;
    }
};