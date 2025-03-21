class Solution {
public:
    long long reverse(int x) {
        bool sign = (x<0);
        long long ans = 0;
        while(x!=0){
            ans *= 10;
            ans += (x%10);
            x/=10;
        }
        if(ans > INT_MAX || ans < INT_MIN) return 0;
        return ans;
    }
};