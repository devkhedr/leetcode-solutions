class Solution {
public:
    int f[26];
    int maxDifference(string s) {
        for(char &x: s) {
            f[x-'a']++;
        }
        int mx = 0, mn = 200;
        for(int i=0;i<26;i++) {
            if(!f[i]) continue;
            if(f[i]%2) mx = max(mx, f[i]);
            else mn = min(mn, f[i]);
        }
        return mx - mn;
    }
};