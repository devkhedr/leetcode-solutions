class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss="", tt="";
        int n=s.length(), cnt = 0;
        for (int i=n-1;i>=0;i--) {
            if(s[i] == '#')cnt++;
            else {
                if(cnt)cnt--;
                else ss += s[i];
            }
        }
        n=t.length(), cnt= 0;
        for (int i=n-1;i>=0;i--) {
            if(t[i] == '#')cnt++;
            else {
                if(cnt)cnt--;
                else tt += t[i];
            }
        }
        return (ss==tt);
    }
};