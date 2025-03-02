class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, l = 0;
        for(int i=0;i<gain.size();i++) {
            l += gain[i];
            ans = max(ans, l);
        }
        return ans;
    }
};