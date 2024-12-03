class Solution {
public:
    bool isHappy(int n) {
        long long sum = 0, digg = 0;
        string s = "hi";
        for(int i=0;i<1000;i++) {
            if(n == 1) return true;
            s = to_string(n);
            sum = 0;
            for(char dig: s) {
                digg = dig-'0';
                sum += digg*digg;
            }
            n = sum;
        }
        return false;
    }
};