class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , vector<int>> mp;
        for(int i=0;i<strs.size();i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it: mp) {
            vector<string> cur;
            for(int i: it.second) {
                cur.push_back(strs[i]);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};