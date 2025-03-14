class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        auto check = [&] (int mid) {
            long long cnt = 0;
            for(int i=0;i<n;i++) {
                cnt += candies[i] / mid;
                if(cnt >= k) return 1;
            }
            return 0;
        };
        int low = 1, high = 1e7, ans = 0, mid;
        while(low <= high) {
            mid = low + (high-low) / 2;
            if(check(mid)) ans = mid, low = mid + 1;
            else high=mid-1;
        }
        return ans;
    }
};