class Solution {
public:
    bool prime[1000001];
    vector<int> closestPrimes(int left, int right) {
        for(int i=0;i<=right;i++) prime[i] = 1;
        vector<int>p;
        prime[0]=prime[1] = 0;
        for(int i=2;i*i<=right;i++) {
            if(prime[i]) {
                for(int j=i*i;j<=right;j+=i) prime[j] = 0;
            }
        }
        for(int i=left;i<=right;i++) {
            if(prime[i]) p.push_back(i);
        }
        int mn = INT_MAX, l=-1, r=-1;
        for(int i: p) cout << i << ' ';
        for(int i=1;i<p.size();i++) {
            if(p[i] - p[i-1] < mn) mn = p[i]-p[i-1], l=p[i-1], r = p[i];
        }
        return {l, r};
    }
};