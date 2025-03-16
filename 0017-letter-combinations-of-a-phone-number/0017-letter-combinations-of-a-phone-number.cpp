class Solution {
public:
    map<int, vector<char>>mp;
    vector<string> res;
    void rec(string s, string nums, int i)
    {
        if(i == nums.size())
        {
            res.push_back(s);
            return;
        }
        for(char it: mp[nums[i]-'0'])
            rec(s+it, nums, i+1);
    }
    vector<string> letterCombinations(string nums) {
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
        if(nums.size() == 0)return res;
        rec("", nums, 0);
        return res;
    }
};