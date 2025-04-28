class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> p(n+1);
        for(int i=1;i<=n;i++) {
            p[i] = nums[i-1] +p[i-1];
        }
        long long ans  = 0,l,r,sol,mid;
        for(int i=1;i<=n;i++) {
            l = i, r = n, mid, sol = i-1;
            while(l <= r) {
                mid = (l + r) >> 1;
                if((p[mid] - p[i-1]) * (mid - i + 1)< k) sol = mid, l = mid +1;
                else r = mid - 1;  
            }
            ans += (sol - i + 1);
        }
        return ans;
    }
};