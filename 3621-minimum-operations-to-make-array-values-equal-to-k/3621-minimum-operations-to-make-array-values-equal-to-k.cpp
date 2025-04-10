class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        sort(nums.begin(), nums.end());
        if(nums[0] < k) return -1;
        cnt += (nums[0] > k);
        for(int i=1;i<n;i++) {
            cnt += (nums[i] != nums[i-1] && nums[i] > k);
        }
        return cnt;
    }
};