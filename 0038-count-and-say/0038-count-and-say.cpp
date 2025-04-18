class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int cnt = 0;
        for(int i=1;i<n;i++) {
            string t = "";
            cnt = 1;
            for(int j=1;j<s.length();j++) {
                if(s[j] != s[j-1]) {
                    t += to_string(cnt);
                    t += s[j-1];
                    cnt = 1;
                }
                else cnt++;
            }
            t += to_string(cnt), t+= s.back();
            s = t;
        }
        return s;
    }
};