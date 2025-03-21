class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int mn = INT_MAX, sol = -1;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    int dif = abs(max(sum, target) - min(sum, target));
                    if(dif < mn) {
                        mn = dif, sol = sum;
                    }
                }
            }
        }
        return sol;
    }
};