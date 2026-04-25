class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();

        auto perim = [&](long long x, long long y) -> long long {
            if (y == 0)    return x;
            if (x == side) return (long long)side + y;
            if (y == side) return 2LL*side + (side - x);
            return 3LL*side + (side - y);
        };

        vector<tuple<long long,int,int>> P(n);
        for (int i = 0; i < n; ++i)
            P[i] = {perim(points[i][0], points[i][1]), points[i][0], points[i][1]};
        sort(P.begin(), P.end());

        vector<int> X(n), Y(n);
        for (int i = 0; i < n; ++i) { X[i] = get<1>(P[i]); Y[i] = get<2>(P[i]); }

        auto md = [&](int i, int j) -> long long {
            return (long long)abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
        };

        vector<int> nxt(n);

        auto check = [&](long long D) {
            int j = 1;
            for (int i = 0; i < n; ++i) {
                if (j < i + 1) j = i + 1;
                while (j < i + n && md(i, j % n) < D) ++j;
                nxt[i] = (j < i + n) ? (j % n) : -1;
            }
            for (int s = 0; s < n; ++s) {
                int cur = s;
                long long covered = 0;
                bool ok = true;
                for (int t = 0; t < k - 1; ++t) {
                    int nx = nxt[cur];
                    if (nx < 0) { ok = false; break; }
                    long long d = ((long long)nx - cur + n) % n;
                    if (d == 0) d = n;
                    if (covered + d >= n) { ok = false; break; }
                    covered += d;
                    cur = nx;
                }
                if (ok && md(cur, s) >= D) return true;
            }
            return false;
        };

        long long lo = 0, hi = 4LL * side, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (check(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return (int)ans;
    }
};