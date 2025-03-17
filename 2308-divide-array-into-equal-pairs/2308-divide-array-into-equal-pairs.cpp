class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> v(501);
        for(int &x: nums) v[x]++;
        for(int &x: nums) {
            if(v[x]%2) return 0;
        }
        return 1;
    }
};