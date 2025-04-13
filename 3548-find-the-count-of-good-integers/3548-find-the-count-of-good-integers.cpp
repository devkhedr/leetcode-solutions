class Solution {
public:
    set<vector<int>> processed;
    vector<long long> factorial;

    void precompute_factorials() {
        factorial.resize(11);
        factorial[0] = 1;
        for (int i = 1; i <= 10; ++i) {
            factorial[i] = factorial[i-1] * i;
        }
    }

    vector<int> get_counts(long long x) {
        vector<int> counts(10, 0);
        if (x == 0) {
            counts[0] = 1;
            return counts;
        }
        while (x > 0) {
            counts[x % 10]++;
            x /= 10;
        }
        return counts;
    }

    long long compute_permutations(const vector<int>& counts, int n) {
        long long denominator = 1;
        for (int d = 0; d < 10; ++d) {
            if (counts[d] > 0) {
                denominator *= factorial[counts[d]];
            }
        }

        long long total = factorial[n];
        if (counts[0] == 0) {
            return total / denominator;
        } else {
            long long subtract = factorial[n-1] * counts[0];
            return (total - subtract) / denominator;
        }
    }

    long long solve(string s, int len, int k, int n) {
        if (s.length() == len) {
            string t = s;
            reverse(t.begin(), t.end());
            if (n % 2) t.erase(0, 1);
            string palindrome_str = s + t;
            long long palindrome = stoll(palindrome_str);
            if (palindrome % k != 0) return 0;

            vector<int> counts = get_counts(palindrome);
            if (processed.find(counts) != processed.end()) return 0;
            processed.insert(counts);

            return compute_permutations(counts, n);
        }

        long long ans = 0;
        for (int i = 0; i < 10; ++i) {
            if (s.empty() && i == 0) continue;
            ans += solve(s + char(i + '0'), len, k, n);
        }
        return ans;
    }

    long long countGoodIntegers(int n, int k) {
        precompute_factorials();
        processed.clear();
        int len = (n + 1) / 2;
        long long ans = 0;
        for (int i = 1; i <= 9; ++i) {
            ans += solve(string(1, '0' + i), len, k, n);
        }

        return ans;
    }
};