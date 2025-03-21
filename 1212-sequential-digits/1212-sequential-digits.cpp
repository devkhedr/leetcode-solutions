class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++) {
            int cur = 0;
            for(int j=i;j<=9;j++) {
                cur *= 10, cur += j;
                if(cur >= low && cur <= high) ans.push_back(cur);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};