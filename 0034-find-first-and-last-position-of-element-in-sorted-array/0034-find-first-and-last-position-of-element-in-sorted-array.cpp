class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid,l = 0, r = (int)nums.size() - 1, fir = -1, last = -1;
        while(l <= r) {
            mid = (l + r) >> 1;
            if(nums[mid] >= target) {
                if(nums[mid] == target)fir = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        } 
        l = 0, r = (int)nums.size() - 1;
        while(l <= r) {
            mid = (l+r) >> 1;
            if(nums[mid] <= target) {
                if(nums[mid] == target)last = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return {fir, last};
    }
};