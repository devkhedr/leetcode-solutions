class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx=0;
        for(int i=0;i<t.length();i++) {
            if(idx == s.length()) return 1;
            if(s[idx] == t[i]) idx++;
        }
        if(idx == s.length()) return 1;
        return 0;
    }
};