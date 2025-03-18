class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i: nums1)
            v.push_back(i);

        for(int i: nums2)
            v.push_back(i);        
        sort(v.begin(), v.end());
        int n = v.size();
        if(n&1)
            return v[n/2];
        else
            return (double)(v[n/2]+v[n/2-1]) / 2.0;
    }
};