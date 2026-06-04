class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt = 0, subcnt = 0;
        for(int x=num1; x<= num2; x++) {
            string s = to_string(x);
            subcnt = 0;
            for(int i=1;i<s.size()-1;i++) {
                if((s[i]-'0') < (s[i+1]-'0') and (s[i]-'0') < (s[i-1]-'0'))
                    subcnt++;
                else if((s[i]-'0') > (s[i+1]-'0') and (s[i]-'0') > (s[i-1]-'0'))
                    subcnt++;
            }
            cnt += subcnt;
        }
        return cnt;
    }
};