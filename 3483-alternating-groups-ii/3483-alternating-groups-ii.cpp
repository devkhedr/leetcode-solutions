class Solution {
public:
int p[100001];
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        // vector<int> p(n+1);
        p[1] = (colors[0] != colors[n-1]);
        for(int i=2;i<=n;i++) {
            p[i] = p[i-1] + (colors[i-1] != colors[i-2]);
        }
        for(int i=1;i<=n;i++) cout << p[i] << ' ';
        int l = 1, r = k;
        int ans = 0;
        while(r <= n) {
            ans += ((p[r] - p[l]) == k-1);
            l++, r++;
        }
        for(int i=1;i<=k-1;i++) {
            int before = p[n] - p[n-i+1], after = p[k-i];
            ans += ((before+after) == k-1);
        }
        return ans;
    }
};