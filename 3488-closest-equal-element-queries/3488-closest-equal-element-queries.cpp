class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> v;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            v[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int &x: queries) {
            int sz = v[nums[x]].size();
            if(sz == 1) {
                ans.push_back(-1);
                continue;
            }
            int idx = lower_bound(v[nums[x]].begin(), v[nums[x]].end(), x) - v[nums[x]].begin();
            int next = v[nums[x]][(idx+1)%sz];
            int prev = v[nums[x]][(idx-1+sz)%sz];
            int d1 = abs(next - x), d2 = abs(prev - x);
            int xx = min(min(d1, n-d1), min(d2, n-d2));
            ans.push_back(xx);
        }
        return ans;
    }
};
