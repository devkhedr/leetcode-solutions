class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, cnt = 0;
        vector<int>nums(nums1.begin(), nums1.end());
        while(i < m && j < n) {
            if(nums[i] < nums2[j]) {
                nums1[cnt] = nums[i];
                cnt++;
                i++;
            }
            else {
                nums1[cnt] = nums2[j];
                cnt++;
                j++;
            }
        }
        while(i < m) {
            nums1[cnt] = nums[i];
            cnt++;
            i++;
        }
        while(j < n) {
            nums1[cnt] = nums2[j];
            cnt++;
            j++;
        }
    }
};