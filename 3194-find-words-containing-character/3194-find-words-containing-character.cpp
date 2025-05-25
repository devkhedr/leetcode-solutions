class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int idx =0 ;
        vector<int> ans;
        for(auto &it: words) {
            bool ok = 0;
            for(int i=0;i<it.size();i++) {
                if(it[i] == x) ok=1;
            }
            if(ok) ans.push_back(idx);
            idx++;
        }
        return ans;
    }
};