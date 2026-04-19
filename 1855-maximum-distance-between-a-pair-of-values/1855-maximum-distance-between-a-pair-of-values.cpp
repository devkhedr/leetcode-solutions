class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int max_dist = 0;
        int n = nums1.size(), m = nums2.size();

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                max_dist = max(max_dist, j - i);
                j++;
            }
            else
                i++;
        }
        return max_dist;
    }
};