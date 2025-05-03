class Solution {
public:
    bool is_equal(int &x, int &y) {
        return x==y;
    }
    int cost(vector<int>&x, vector<int> &y, int val) {
        int n = x.size(), cnt = 0;
        for(int i=0;i<n;i++) {
            if(x[i] == val) continue;
            else if(y[i] == val) cnt++;
            else return INT_MAX;
        }
        return cnt;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        for(int i=0;i<n;i++) {
            if(!is_equal(tops[i], tops[0]) and !is_equal(tops[i], bottoms[0]) and !is_equal(bottoms[i], tops[0]) and !is_equal(bottoms[i], bottoms[0])) return -1;
        }
        int mn = INT_MAX;
        mn = min(mn, cost(tops, bottoms, tops[0]));
        mn = min(mn, cost(tops, bottoms, bottoms[0]));
        mn = min(mn, cost(bottoms, tops, tops[0]));
        mn = min(mn, cost(bottoms, tops, bottoms[0]));
        return mn == INT_MAX ? -1: mn;
    }
};