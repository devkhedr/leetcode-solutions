class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n+1), s(n+3);
        p[0] = 1;
        for(int i=1;i<=n;i++) p[i] = p[i-1]*nums[i-1];
        s[n+1] = 1;
        for(int i=n;i>=1;i--) s[i] = s[i+1]*nums[i-1];
        vector<int> ans;
        for(int i=1;i<=n;i++) {
            ans.push_back(p[i-1]*s[i+1]);
        }
        return ans;
    }
};