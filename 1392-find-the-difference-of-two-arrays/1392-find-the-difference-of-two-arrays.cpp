class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int>l1,l2;
        map<int, int>mp1, mp2;
        for(int i: nums1) mp1[i]++;
        for(int i: nums2) mp2[i]++;
        for(auto it: mp1) {
            if(!mp2[it.first])
                l1.push_back(it.first);
        }
        for(auto it: mp2) {
            if(!mp1[it.first])
                l2.push_back(it.first);
        }
        vector<vector<int>>ans = {l1,l2};
        return ans;
    }
};