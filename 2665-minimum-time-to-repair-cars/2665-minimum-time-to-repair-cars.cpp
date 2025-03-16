class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        auto check = [&] (long long mid) {
            long long cnt = 0;
            for(int &x: ranks) {
                cnt += sqrt(mid / x);
                if(cnt>=cars) return 1;
            }
            return 0;
        };
        long long low = 1 , high = 1e16, sol=0, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(check(mid)) sol = mid, high = mid - 1;
            else low = mid + 1;
        }
        return sol;
    }
};