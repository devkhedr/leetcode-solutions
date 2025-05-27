class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum1 = n * (n+1) / 2;
        int x = n / m;
        int ax = m + (x-1)*m;
        int sum2 = (m + ax) * x / 2;
        return sum1 -2*sum2;
    }
};