class Solution {
public:
    vector<int> modify_arr(vector<int> &nums) {
        vector<int> n;
        map<int, int> mp;
        for(int &x: nums) mp[x]++;
        for(auto it: mp) {
            for(int i=0;i<min(it.second, 3);i++) {
                n.push_back(it.first);
            }
        }
        sort(n.begin(), n.end());
        return n;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        nums = modify_arr(nums);
        int n = nums.size();
        map<int, int> mp;
        for(int i=0;i<n;i++) {
            mp[nums[i]]= i;
        }
        vector<vector<int>>ans;
        map<vector<int>, bool> taken;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int k = -(nums[i]+nums[j]);
                if(mp[k] > j) {
                    if(taken[{nums[i], nums[j], k}]) continue;
                    ans.push_back({nums[i], nums[j], k});
                    taken[{nums[i], nums[j], k}] = 1;
                }
            }
        }
        return ans;
    }
};