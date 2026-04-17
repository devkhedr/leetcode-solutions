class Solution {
public:
    int reverse(int &x) {
        int rev = 0;
        while(x > 0) {
            rev*=10, rev += (x%10);
            x /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for(int i=1;i<=n;i++) {
            int x = nums[i-1], y = reverse(nums[i-1]);
            if(mp[x]) ans = min(ans, i-mp[x]);
            mp[y] = i; 
        }
        return (ans == INT_MAX) ? -1: ans;
    }
};