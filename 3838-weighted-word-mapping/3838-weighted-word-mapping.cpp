class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        int n = words.size();
        for(int i=0;i<n;i++) {
            int cnt = 0;
            for(char &c: words[i]) {
                cnt += weights[c-'a'];
            }    
            cnt%=26;
            ans += char(25-cnt+'a');
        }
        return ans;
    }
};