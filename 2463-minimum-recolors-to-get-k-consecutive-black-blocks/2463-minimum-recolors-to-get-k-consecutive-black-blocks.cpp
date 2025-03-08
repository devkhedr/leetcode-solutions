class Solution {
public:
    int w[101], b[101];
    int minimumRecolors(string blocks, int k) {
        for(int i=1;i<=blocks.size();i++) {
            w[i] = w[i-1] + (blocks[i-1] == 'W');
            b[i] = b[i-1] + (blocks[i-1] == 'B');
        }
        int l = 1, r = k, mn = INT_MAX;
        while(r <= blocks.size()) {
            mn = min(mn, w[r] - w[l-1]);
            l++, r++;
        }
        return mn;
    }
};