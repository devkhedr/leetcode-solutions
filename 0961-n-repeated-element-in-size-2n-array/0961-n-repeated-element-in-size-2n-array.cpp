class Solution {
public:
    int f[10001];
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        for(int &i: nums) {
            f[i]++;
            if(f[i] == n) return i;
        }
        return 0;
    }
};