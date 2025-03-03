class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        vector<int> v;
        for(int &i: nums) {
            if(i!=0) v.push_back(i);
            else cnt++;
        }
        while(cnt--) v.push_back(0);
        nums=v;
    }
};