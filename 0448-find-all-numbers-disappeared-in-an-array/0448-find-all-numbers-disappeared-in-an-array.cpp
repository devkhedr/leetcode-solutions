class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>res;
        int n = nums.size();
        vector<bool>vis(n+1);
        for(auto it:nums)
        {
            vis[it] = 1;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                res.push_back(i);
        }
        return res;
        
    }
};