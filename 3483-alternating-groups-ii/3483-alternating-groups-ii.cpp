class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=1;i<=k-1;i++) colors.push_back(colors[i-1]);
        int n = colors.size();
        vector<int> p(n+1);
        for(int i=2;i<=n;i++) {
            p[i] = p[i-1] + (colors[i-1] ^ colors[i-2]);
        }
        int l = 1, r = k;
        int ans = 0;
        while(r <= n) {
            ans += ((p[r] - p[l]) == k-1);
            l++, r++;
        }
        return ans;
    }
};