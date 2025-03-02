class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n+1),s(n+3);
        p[0] = nums[0];
        for(int i=1;i<n;i++)
            p[i] = p[i-1] + nums[i];
        s[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
            s[i] = s[i+1] + nums[i];
        if(n == 1) return 0;
        for(int i=0;i<n;i++) {
            if(i == 0) {
                if(s[1] == 0) return 0;
            }
            else if(i == n-1) {
                if(p[n-2] == 0) return n-1;
            }
            else {
                if(p[i-1] == s[i+1])
                    return i;
            }
        }
        return -1;
    }
};