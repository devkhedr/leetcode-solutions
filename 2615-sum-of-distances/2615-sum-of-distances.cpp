class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, long long> last_pos, cnt;
        vector<long long> ans(n);
        for(int i=0;i<n;i++) last_pos[nums[i]] = -1;
        for(int i=0;i<n;i++) {
            if(~last_pos[nums[i]])
                ans[i] += (cnt[nums[i]] * i) - last_pos[nums[i]];
            if(last_pos[nums[i]] == -1) last_pos[nums[i]] = 0;
            last_pos[nums[i]] += i;
            cnt[nums[i]]++;
        }
        for(int i=0;i<n;i++) last_pos[nums[i]] = -1, cnt[nums[i]]=0;
        for(int i=n-1;i>=0;i--) {
            if(~last_pos[nums[i]])
                ans[i] += last_pos[nums[i]] - (cnt[nums[i]] * i);
            if(last_pos[nums[i]] == -1) last_pos[nums[i]] = 0;
            last_pos[nums[i]] += i;
            cnt[nums[i]]++;
        }
        return ans;
    }
};