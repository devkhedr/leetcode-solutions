class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<unordered_map<int,int>> dp;
    int modInverse(int a) {
        int base = a, exponent = MOD - 2, result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (1LL * result * base) % MOD;
            }
            base = (1LL * base * base) % MOD;
            exponent /= 2;
        }
        return result;
    }

    int comb(int n, int r) {
        if (r > n) return 0;
        if (r == 0) return 1;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - r + i) % MOD;
            int inv = modInverse(i);
            res = res * inv % MOD;
        }
        return res;
    }

    int solve(int k, int val, int n, int maxValue) {
        if (k>n) return 0;
        if (k==n) return comb(n-1, k-1);
        if (dp[k].count(val)) return dp[k][val];
        int count = comb(n-1, k-1);
        for (int i=2;i<=maxValue/val;i++) {
            int next_val=val* i;
            if (next_val>maxValue) break;
            count = (count+solve(k+1,next_val, n, maxValue)) % MOD;
        }
        return dp[k][val] = count;
    }

    int idealArrays(int n, int maxValue) {
        dp.clear();
        dp.resize(n + 2);
        int total = 0;
        for (int i=1;i<=maxValue;i++) {
            total=(total+solve(1, i, n, maxValue)) % MOD;
        }
        return total;
    }
};