class Solution {
public:
    int kthFactor(int n, int k) {
        int ans = -1;
        vector<int> f;
        for(int i=1;i*i<=n;i++) {
            if(n%i == 0) {
                f.push_back(i);
                if(i*i != n) f.push_back(n/i);
            }
        }
        sort(f.begin(), f.end());
        if(k <= f.size()) return f[k-1];
        return -1;
    }
};