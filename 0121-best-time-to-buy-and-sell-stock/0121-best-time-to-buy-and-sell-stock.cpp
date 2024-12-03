class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxres = 0, mn = INT_MAX;
        for(int it: prices)
        {
            mxres = max(mxres, it-mn);
            mn = min(mn, it);
        }
        return mxres;
    }
};