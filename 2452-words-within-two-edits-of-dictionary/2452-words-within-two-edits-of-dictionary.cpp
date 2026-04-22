class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string &x: queries) {
            bool found = 0;
            for(string &y: dictionary) {
                int cnt = 0;
                for(int i=0;i<y.size();i++) {
                    cnt += (x[i] != y[i]);
                }
                if(cnt <= 2) found = 1; 
            }
            if(found) ans.push_back(x);
        }
        return ans;
    } 
};