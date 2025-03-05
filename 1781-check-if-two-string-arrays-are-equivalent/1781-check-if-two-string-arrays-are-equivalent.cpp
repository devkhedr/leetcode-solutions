class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s, t;
        s=t="";
        for(string cc: word1) s+=cc;
        for(string cc: word2) t+=cc;
        return s==t;
    }
};