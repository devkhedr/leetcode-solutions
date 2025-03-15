class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        auto check = [&](int &mid) {
            cnt = 0;
            for(int i=0;i<n;i++) {
                if(nums[i] <= mid) cnt++,i++;
                if(cnt>=k) return 1;
            }
            return 0;
        };
        int low = 1, high = 1e9, sol = 0, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(check(mid)) sol = mid, high = mid - 1;
            else low = mid + 1;
        }
        return sol;
    }
};