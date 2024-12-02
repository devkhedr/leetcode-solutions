class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>w;
        string word = "";
        for(char &ch: sentence) {
            if(ch == ' ')w.push_back(word), word = "";
            else word += ch;
        }
        w.push_back(word);
        int ans = -1, cnt = 0;
        for(string wo: w) {
            ++cnt;
            if(wo.length() >= searchWord.length() && wo.substr(0, searchWord.length()) == searchWord) {
                ans = cnt;
                break;
            }
        }
        return ans;
    }
};