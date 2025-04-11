class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int x=low;x<=high;x++) {
            string s = to_string(x);
            if(s.length()&1)continue;
            int sum1 = 0, sum2 = 0;
            for(int i=0;i<s.length()/2;i++) sum1 += (s[i]-'0');
            for(int i=s.length()/2;i<s.length();i++) sum2 += (s[i]-'0');
            if(sum1 == sum2) cnt++;
        }
        return cnt;
    }
};