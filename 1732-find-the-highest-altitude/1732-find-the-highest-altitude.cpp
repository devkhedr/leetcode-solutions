class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int last = 0, mx = 0;
        for(int &x: gain) {
            last += x;
            mx = max(mx, last);
        }
        return mx;
    }
};