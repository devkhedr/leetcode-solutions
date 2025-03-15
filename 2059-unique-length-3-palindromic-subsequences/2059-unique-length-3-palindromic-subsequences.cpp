class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>v[26];
        for(int i=0;i<s.length();i++) {
            v[s[i]-'a'].push_back(i);
        }   
        int cnt = 0; 
        for(int i=0;i<26;i++) {
            if(v[i].size() >= 2 && v[i].back()-v[i][0] > 1) {
                for(int j=0;j<26;j++) {
                    if(upper_bound(v[j].begin(), v[j].end(), v[i][0]) != v[j].end()) {
                        int idx = upper_bound(v[j].begin(), v[j].end(), v[i][0]) - v[j].begin();
                        if(v[j][idx] <v[i].back()){
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};