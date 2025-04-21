class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<long long> d;
        for(int &y: differences) d.push_back(y);
        long long x = 0;
        vector<long long> s = {x};
        long long n = d.size();
        for(long long &i: d) {
            s.push_back(i+s.back());
        }
        long long mx = *max_element(s.begin(), s.end());
        mx -= upper;
        for(long long &i: s) i -= mx;
        long long mn = *min_element(s.begin(), s.end());
        mn -= lower;
        for(long long &i: s) i -= mn;
        mx = *max_element(s.begin(), s.end());
        return max(0LL, (long long)upper -(long long)mx + 1LL);
    }
};