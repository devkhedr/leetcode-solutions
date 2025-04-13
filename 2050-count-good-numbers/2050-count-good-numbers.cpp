class Solution {
public:
    const int MOD = 1e9 + 7;
    long long mult(long long a, long long b) {
        return a%MOD * b%MOD % MOD;
    }
    long long fast_power_modulo(long long n, long long x) {
        long long result = 1;
        while (x > 0) {
            if (x % 2 == 1) {
                result = mult(result, n);
            }
            n = mult(n, n);
            x>>=1;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long evcnt = (n/2) + (n%2), odcnt = n/2;
        cout << evcnt << ' ' << odcnt << '\n';
        long long evans = mult(5, fast_power_modulo(5, evcnt-1));
        long long odans = fast_power_modulo(4, odcnt);
        return mult(evans, odans);
    }
};