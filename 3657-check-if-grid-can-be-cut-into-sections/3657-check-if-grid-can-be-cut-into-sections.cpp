class Solution {
public:
    vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> &v) {
        sort(v.begin(), v.end());
        vector<pair<int, int>> merged;
        for(auto &it: v) {
            if(merged.empty() || it.first >= merged.back().second) merged.push_back(it);
            else {
                merged.back().second = max(merged.back().second, it.second);
            }
        }
        return merged;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> v;
        for(auto &it: rectangles) {
            v.push_back({it[0], it[2]});
        }
        vector<pair<int, int>> merged = mergeIntervals(v);
        if(merged.size() >= 3) return 1;
        v.clear(), merged.clear();
        for(auto &it: rectangles) {
            v.push_back({it[1], it[3]});
        }
        merged = mergeIntervals(v);
        if(merged.size() >= 3) return 1;
        return 0;
    }
};