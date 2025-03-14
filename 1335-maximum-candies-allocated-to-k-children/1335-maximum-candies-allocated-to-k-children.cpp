class Solution {
public:
    bool check(int mid, vector<int> &candies, long long &k) {
        long long cnt = 0;
        for(int i=0;i<candies.size();i++) {
            cnt += candies[i] / mid;
            if(cnt >= k) return 1;
        }
        return 0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = 1e7, ans = 0, mid;
        while(low <= high) {
            mid = low + (high-low) / 2;
            if(check(mid, candies, k)) ans = mid, low = mid + 1;
            else high=mid-1;
        }
        return ans;
    }
};