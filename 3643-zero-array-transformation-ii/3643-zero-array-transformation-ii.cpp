class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        auto check = [&](int mid) {
            vector<int> p(n+2);
            for(int i=0;i<mid;i++) {
                p[queries[i][0]+1]-=queries[i][2];
                p[queries[i][1]+2]+=queries[i][2];
            }
            for(int i=1;i<=n;i++) {
                p[i]+=p[i-1];
            }
            for(int i=1;i<=n;i++) {
                p[i] += nums[i-1];
                if(p[i] > 0) return 0;
            }
            return 1;
        };
        int l = 0, r = queries.size(), mid, ans = -1;
        while(l <= r) {
            mid = l + (r-l) / 2;
            if(check(mid)) ans= mid, r= mid - 1;
            else l = mid + 1;
        }
        return ans;
        return 1;
    }
};