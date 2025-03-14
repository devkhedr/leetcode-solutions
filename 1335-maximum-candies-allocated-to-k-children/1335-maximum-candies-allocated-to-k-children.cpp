class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        auto check = [&] (long long  mid) {
            long long cnt = 0;
            for(int i=0;i<n;i++) {
                cnt += candies[i] / mid;
                if(cnt >= k) return 1;
            }
            return 0;
        };
        long long l = 1, r = 1e7, ans = 0, mid;
        while(l <= r) {
            mid = l + (r-l) / 2;
            if(check(mid)) ans = mid, l = mid + 1;
            else r=mid-1;
        }
        return ans;
    }
};