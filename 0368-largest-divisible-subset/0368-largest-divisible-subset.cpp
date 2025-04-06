class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        sort(nums.begin(), nums.end());
        for(int i=n-1;i>=0;i--) {
            int x = 0;
            for(int j=i+1;j<n;j++) {
                if(nums[j]%nums[i] == 0) {
                    x = max(x, mp[nums[j]]);
                }
            }
            mp[nums[i]] = 1 + x;
        }
        int mx = 0, item = 0;
        for(int &x: nums) {
            if(mp[x] > mx) mx = mp[x], item = x;
        }
        vector<int> ans;
        while(true) {
            ans.push_back(item);
            int it = -1;
            mx = 0;
            for(int &x: nums) {
                if(x > item && x% item == 0) {
                    if(mp[x] > mx) mx = mp[x], it = x;
                }
            }
            item = it;
            if(item == -1) break;
        }
        return ans;
    }
}; 