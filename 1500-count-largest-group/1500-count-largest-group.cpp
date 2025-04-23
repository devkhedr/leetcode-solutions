class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> cnt1(50), cnt2(10001);
        for(int i=1;i<=n;i++) {
            int sum = 0;
            string t = to_string(i);
            for(char j:t) {
                sum += (j-'0');
            }
            cnt1[sum]++;
        }
        for(int i=0;i<=45;i++) cnt2[cnt1[i]]++;
        int ans = 0;
        for(int i=0;i<=10000;i++) {
            if(cnt2[i] > 0)
                ans = cnt2[i];
        }
        return ans;
    }
};