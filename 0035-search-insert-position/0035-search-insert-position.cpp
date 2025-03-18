class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid = 0;
        int sol = r + 1;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(nums[mid] >= target) sol = mid, r = mid - 1;
            else l = mid + 1;
        }
        return sol;
    }
};