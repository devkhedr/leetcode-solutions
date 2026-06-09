using ll = long long;
pair<ll, ll> dp[17][2][2][10][10][3];
int cached[17][2][2][10][10][3];
int test = 0;
class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        test++;
        string l = to_string(num1);
        string r = to_string(num2);
        l = string(r.size() - l.size(), '0') + l;
        const int N = l.size();
        auto dfs = [&](auto& dfs, int i = 0, int t1 = 1, int t2 = 1, int l1 = 0, int l2 = 0, int st = 0) -> pair<ll, ll> { // num, waviness
            if(i == N) return {1, 0};
            auto& res = dp[i][t1][t2][l1][l2][st];
            auto& c = cached[i][t1][t2][l1][l2][st];
            if(c == test) return res;
            c = test;
            res = {0, 0};
            int low = t1 ? l[i] - '0' : 0;
            int high = t2 ? r[i] - '0' : 9;
            for(int d = low; d <= high; d++) {
                auto it = dfs(dfs, i + 1, t1 && d == low, t2 && d == high, l2, d, st == 0 && d == 0 ? 0 : min(2, st + 1));
                res.first += it.first;
                res.second += it.second;
                if(st >= 2 && ((l2 > l1 && l2 > d) || (l2 < l1 && l2 < d))) {
                    res.second += it.first;
                }
            }
            return res;
        };
        return dfs(dfs).second;
    }
};