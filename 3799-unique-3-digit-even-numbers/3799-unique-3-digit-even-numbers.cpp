class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> vis(10);
        for(int i: digits) {
            vis[i]++;
        }
        int cnt = 0;
        for(int i=100;i<=998;i+=2) {
            vector<int> comp = vis;
            string s = to_string(i);
            bool ok = 1;
            for(char c: s) {
                if(!vis[c-'0']) ok = 0;
                else vis[c-'0']--;
            }
            vis = comp;
            cnt += ok;
        }
        return cnt;
    }
};