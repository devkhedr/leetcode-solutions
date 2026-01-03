class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9+7;
        long long SameColor = 6, DiffColor  = 6;

        for (int i = 2; i <= n; i++) {
            long long NewSameColor = (2 * SameColor+ 2 * DiffColor) % MOD;
            long long NewDiffColor = (2 * SameColor+ 3 * DiffColor) % MOD;
            SameColor = NewSameColor;
            DiffColor = NewDiffColor;
        }

        return (SameColor + DiffColor) % MOD;
    }
};