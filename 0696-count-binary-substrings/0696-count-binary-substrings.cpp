class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length(), cnt = 1, ans = 0;
        vector<int> v;
        for(int i=1;i<n;i++) {
            if(s[i] == s[i-1]) cnt++;
            else {
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);
        int sz = v.size();
        for(int i=1;i<sz;i++) {
            ans += min(v[i], v[i-1]);
        }
        return ans;
    }
};