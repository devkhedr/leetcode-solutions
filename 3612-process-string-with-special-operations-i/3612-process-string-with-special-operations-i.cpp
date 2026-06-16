class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(char &c: s) {
            if (c == '#') {
                ans += ans;
            } else if(c == '*') {
                if (!ans.empty())
                    ans.pop_back();
            } else if(c == '%') {
                reverse(ans.begin(), ans.end());
            } else {
                ans += c;
            } 
        }
        return ans;
    }
};