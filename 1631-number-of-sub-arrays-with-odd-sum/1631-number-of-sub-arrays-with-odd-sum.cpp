class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1;
        int prefixSum = 0, result = 0;

        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2) {
                result = (result + evenCount) % MOD;
                oddCount++;
            } else {
                result = (result + oddCount) % MOD;
                evenCount++;
            }
        }

        return result;
    }
};
