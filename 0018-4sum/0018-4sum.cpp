class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        unordered_map<int, int> f;
        for(int i=0;i<n;i++) f[nums[i]] = i+1;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    long long sum = nums[i];
                    sum += nums[j], sum += nums[k];
                    int fourth = target - sum;
                    if(target - sum != fourth) continue;
                
                    if(f[fourth] - 1 > k) {
                        ans.insert({nums[i], nums[j], nums[k], (int)fourth});
                    }
                }
            }
        }
        vector<vector<int>> anss;
        for(auto &x: ans) anss.push_back(x);
        return anss;
    }
};