class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        auto cmp = [](const pair<double,pair<int,int>>& a,const pair<double, pair<int,int>>& b) {
            return a.first < b.first;
        };

        priority_queue<pair<double,pair<int,int>>,vector<pair<double, pair<int,int>>>, decltype(cmp)> pq(cmp);
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--) {
            auto [delta, st] = pq.top(); pq.pop();
            st.first++, st.second++;
            pq.push({gain(st.first, st.second), st});
        }

        double ans = 0.0;
        while (!pq.empty()) {
            auto st = pq.top().second;
            ans += (double)st.first / st.second;
            pq.pop();
        }
        return ans / (double)classes.size();
    }
};