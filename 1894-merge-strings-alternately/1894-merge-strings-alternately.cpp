class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        bool ok = 1;
        string s = "";
        while(i<word1.size() && j<word2.size()) {
            if(ok) s+=word1[i], i++;
            else s+=word2[j], j++;
            ok ^= 1;
        }
        while(i < word1.size()) s+=word1[i], i++;
        while(j < word2.size()) s+=word2[j], j++;
        return s;
    }
};