class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v;
        for(int i: nums) {
            if(i < pivot) v.push_back(i);
        }for(int i: nums) {
            if(i == pivot) v.push_back(i);
        }for(int i: nums) {
            if(i > pivot) v.push_back(i);
        }
        return v;
    }
};