class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int &x: nums) cnt += ((int)(log10(x)+1)%2 == 0);
        return cnt;
    }
};