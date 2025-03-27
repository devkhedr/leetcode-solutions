class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, mjr = 0;
        for(int x: nums) {
            if(cnt == 0) mjr = x, cnt = 1;
            else if(x == mjr) cnt++;
            else cnt--;
        }
        return mjr;
    }
};