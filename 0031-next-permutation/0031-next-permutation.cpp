class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cnt = 0;
        do {
            cnt++;
        }
        while(next_permutation(nums.begin(), nums.end()) && cnt < 1);
    }
};