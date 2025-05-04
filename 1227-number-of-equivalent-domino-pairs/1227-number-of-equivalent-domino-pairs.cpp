class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        for(auto &x: dominoes) {
            if(x[0] > x[1]) swap(x[0], x[1]);
            mp[{x[0], x[1]}]++;
        }
        int ans = 0;
        for(auto &x: mp) ans += x.second *(x.second-1) / 2;
        return ans;
    }
};