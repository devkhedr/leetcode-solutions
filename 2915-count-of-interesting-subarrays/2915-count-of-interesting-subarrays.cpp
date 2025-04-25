class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int prefix = 0;
        long long ans = 0;
        unordered_map<int, int> countPrefix;
        countPrefix[0] = 1;

        for(int i=0; i<nums.size(); i++) {
            prefix += nums[i] % modulo == k;
            ans += countPrefix[(prefix - k) % modulo];
            countPrefix[prefix % modulo]++;
        }

        return ans;
    }
};