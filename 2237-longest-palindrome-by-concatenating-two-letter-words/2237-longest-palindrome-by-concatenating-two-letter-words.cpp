class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        int n = words.size(), cnt = 0;
        for(string &x: words) {
            string t = "";
            t+=x[1], t += x[0];
            if(mp[t] > 0){
                cout << x <<  " match\n";
                cnt += 4;
                mp[t]--;
            }
            else {
                mp[x]++;
                cout << x << " stored\n";
            }
        }
        for(auto &it: mp) {
            if(it.second > 0 && it.first[0] == it.first[1]) {
                cnt += 2;
                break;
            }
        }
        return cnt;
    }
};