class Solution {
public:
    int numberOfSubstrings(string s) {
        int last_a = -1 , last_b = -1, last_c = -1, n = s.size(), ans = 0;
        for(int i=n-1;i>=0;i--) {
            if(s[i] == 'a') {
                if(last_b != -1 && last_c != -1) {
                    ans += n-max(last_b, last_c);
                }
                last_a = i;
            }
            else if(s[i] == 'b') {
                if(last_a != -1 && last_c != -1) {
                    ans += n-max(last_a, last_c);
                }
                last_b = i;
            }
            else {
                if(last_a != -1 && last_b != -1) {
                    ans += n-max(last_a, last_b);
                }
                last_c = i;
            }
        }
        return ans;
    }
};