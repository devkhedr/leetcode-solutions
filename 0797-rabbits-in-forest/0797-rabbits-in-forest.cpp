class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(auto a : answers)mp[a]++;
        int ans = 0;
        for(auto a : mp){
            int f=a.first,s =a.second;
            ans+=((s+f)/(f+1))*(f+1);
        }
        return ans;
    }
};
