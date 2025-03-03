class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string t="";
        for(char c: s) {
            if(c == ' ') {
                if(t!="") v.push_back(t);
                t="";
            }
            else t+=c;
        }
        if(t!="") v.push_back(t);
        reverse(v.begin(), v.end());
        string ans="";
        for(auto it: v) ans += it, ans+=' ';
        ans.pop_back();
        return ans;
    }
};