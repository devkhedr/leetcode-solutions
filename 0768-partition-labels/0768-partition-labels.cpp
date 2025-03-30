class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(), st = 0, end = 0;
        unordered_map<char, int> mp;
        vector<int> res;

        for(int i = 0; i < n; i++){
            mp[s[i]] = i;
        }

        for(int i = 0; i < n; i++){
            end = max(end, mp[s[i]]);

            if(end == i){
                res.push_back(end - st + 1);
                st = i + 1;
            }
        }

        return res;
    }
};