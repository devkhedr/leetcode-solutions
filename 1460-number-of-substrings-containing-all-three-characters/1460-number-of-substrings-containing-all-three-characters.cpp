class Solution {
public:
    int numberOfSubstrings(string s) {
        int nearest_a = -1 , nearest_b = -1, nearest_c = -1, n = s.size(), ans = 0;
        for(int i=n-1;i>=0;i--) {
            if(s[i] == 'a') {
                if(nearest_b != -1 && nearest_c != -1) {
                    ans += n-max(nearest_b, nearest_c);
                }
                nearest_a = i;
            }
            else if(s[i] == 'b') {
                if(nearest_a != -1 && nearest_c != -1) {
                    ans += n-max(nearest_a, nearest_c);
                }
                nearest_b = i;
            }
            else {
                if(nearest_a != -1 && nearest_b != -1) {
                    ans += n-max(nearest_a, nearest_b);
                }
                nearest_c = i;
            }
        }
        return ans;
    }
};