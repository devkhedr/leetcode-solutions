#include <vector>
#include <cstring> 

using namespace std;

class Solution {
private:
    int sumOf(const vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        return sum;
    }

    bool rec(int i, const vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (sum < 0 || i >= n) return false;
        if (dp[i][sum] != -1) return dp[i][sum] == 1;

        bool dont = rec(i + 1, nums, n, sum, dp);
        bool pick = (nums[i] <= sum) ? rec(i + 1, nums, n, sum - nums[i], dp) : false;
        
        dp[i][sum] = (pick || dont) ? 1 : 0;
        return pick || dont;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = sumOf(nums);
        if (sum % 2 == 1) return false;
        sum /= 2;
        
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return rec(0, nums, n, sum, dp);
    }
};