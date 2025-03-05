class Solution {
public:
    long long coloredCells(int n) {
        long long an = 2*n-1;
        return n+an*(n-1);
    }
};