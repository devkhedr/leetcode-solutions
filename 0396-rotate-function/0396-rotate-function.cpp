class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f0 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            f0 += (i*nums[i]);
            nums.push_back(nums[i]);
        }

        int sum = 0;
        vector<int> prefix;
        for(auto &i : nums){
            sum += i;
            prefix.push_back(sum);
        }

        int maxx = f0;

        int left = n-1;
        int right = 2*n-2;
        while(left > 0){
            int curr = f0-((n-1)*nums[left]) + (prefix[right--]-prefix[left--]);
            maxx = max(maxx, curr);
            f0 = curr;
        }

        return maxx;
    }
};