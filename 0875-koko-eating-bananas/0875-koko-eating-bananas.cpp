class Solution {
public:
    bool check(int &val, int &h, vector<int> &piles) {
        int cur = 0;
        for(int &x: piles) {
            cur += (x+val-1)/val;
            if(cur > h) return 0;
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9, mid, ans = 1e9;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(check(mid, h, piles)) ans = mid, high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};
