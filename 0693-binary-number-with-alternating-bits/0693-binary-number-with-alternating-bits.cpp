class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last=n%2,x;
        n/=2;
        while(n>0) {
            x=n%2;
            n/=2;
            if(x==last)return 0;
            last=x;
        }
        return 1;
    }
};