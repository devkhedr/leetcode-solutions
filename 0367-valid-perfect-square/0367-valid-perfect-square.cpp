class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0, r = num, mid;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(mid * mid == num) return 1;
            else if(mid * mid > num) r=  mid - 1;
            else  l = mid + 1;
        }
        return 0;
    }
};