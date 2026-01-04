class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum, cnt,sol=0;
        vector<int> ans(100001);
        for(int i=1;i<=100000;i++) {
            sum = 1+i, cnt = 2;
            for(int j=2;j*j<=i;j++) {
                if(i%j==0) sum += (j+i/j), cnt+=2;
                if(j*j == i) sum -= j, cnt -= 1;
            }
            // cout <<i << ' ' << cnt << ' ' << sum << '\n';
            if(cnt == 4)ans[i] = sum;
        }
        for(int &i: nums) sol += ans[i];
        return sol;
    }
    
};