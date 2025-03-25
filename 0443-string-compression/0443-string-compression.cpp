class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 1, n = chars.size(), idx=0;
        vector<char> ans;
        for(int i=1;i<n;i++) {
            if(chars[i] == chars[i-1]) cnt++;
            else {
                string num = to_string(cnt);
                ans.push_back(chars[i-1]);
                idx = 0;
                if(num == "1") idx=1;
                while(idx < num.size()) 
                    ans.push_back(num[idx]), idx++;
                cnt = 1;
            }
        }
        string num = to_string(cnt);
        ans.push_back(chars.back());
        idx = 0;
        if(num == "1") idx=1;
        while(idx < num.size()) 
            ans.push_back(num[idx]), idx++;
        chars.clear();
        chars.resize(0);
        for(char &c: ans) chars.push_back(c);
        return chars.size();
    }
};