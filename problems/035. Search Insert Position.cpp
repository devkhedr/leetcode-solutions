// Author: Mohamed Khedr

class Solution {
public:
    // we must insert the number in the place of the first number that greater than or equal to it.
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