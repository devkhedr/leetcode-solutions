class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> v(205);
        for(int &x: nums) v[x]++;
        for(int i=1;i<n;i++) {
            if(v[i] != 1) return 0;
        }
        if(v[n]!=2) return 0;
        return 1;
    }
};