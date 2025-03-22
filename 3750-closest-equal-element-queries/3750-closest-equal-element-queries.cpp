class Solution {
public:
    int cost(int i1, int i2, int n) {
        if(i1>i2) i1^=i2, i2^=i1, i1^=i2;
        return min(i2-i1, (n-i2)+i1);
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int &x: queries) {
            int val = nums[x], sz = mp[val].size();
            if(sz == 1) {
                ans.push_back(-1);
                continue;
            }
            int idx = lower_bound(mp[val].begin(), mp[val].end(), x) - mp[val].begin();
            int next = mp[val][(idx+1) % sz], prev = mp[val][(idx-1+sz)%sz];
            idx = mp[val][idx];
            // cout << val << ' ' << idx << ' '<< next << ' ' << prev << '\n';
            ans.push_back(min(cost(idx, next, n), cost(idx, prev, n)));
        }
        return ans;
    }
};