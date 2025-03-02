class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int>f, ff;
        for(int x: arr)
            f[x]++;
        for(auto x: f) {
            ff[x.second]++;
            if(ff[x.second] > 1)
                return 0;
        }
        return 1;
    }
};