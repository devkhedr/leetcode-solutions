class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(int &i: nums) {
            pos += (i>0);
            neg += (i<0);
        }
        return max(pos, neg);
    }
};