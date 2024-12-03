class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size(), idx = 0;
        string ans = "";
        for(int i=1;i<=n;i++) {
            if(idx < spaces.size() && i == spaces[idx]+1) {
                ans += ' ', ans += s[i-1];
                idx++;
            }
            else ans += s[i-1];
        }
        return ans;
    }
};