class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) 
            return 0;
        vector<int>fr1(26), fr2(26);
        for(char ch: word1) {
            fr1[ch-'a']++;
        }
        for(char ch: word2) {
            fr2[ch-'a']++;
        }
        map<int, int>f1,f2;
        for(char c='a'; c<='z';c++) {
            f1[fr1[c-'a']]++;
            f2[fr2[c-'a']]++;
            if(fr1[c-'a'] && !fr2[c-'a'])
                return 0;
            if(fr2[c-'a'] && !fr1[c-'a'])
                return 0;
        }
        for(auto it: f1) {
            if(it.second != f2[it.first])
                return 0;
        }
        return 1;
    }
};