class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<pair<int, int>> merged;
        for (auto meeting : meetings) {
            if (merged.empty() || merged.back().second < meeting[0]) {
                merged.push_back({meeting[0], meeting[1]});
            } else {
                merged.back().second = max(merged.back().second, meeting[1]);
            }
        }
        int ans = merged[0].first - 1 + max(0, days - merged.back().second);
        for(int i=1;i<merged.size();i++) ans += merged[i].first - merged[i-1].second - 1;
        return ans;
    }
};