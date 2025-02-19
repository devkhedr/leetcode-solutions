class Solution {
public:
    vector<string> v;
    void generate(string &s, char lastchar, int &n) {
        if(s.length() == n) {
            v.push_back(s);
            return;
        }
        for(int i=0;i<3;i++) {
            if(lastchar != 'a'+i) {
                s.push_back('a'+i);
                generate(s, i+'a', n);
                s.pop_back();
            }
        }
    } 
    string getHappyString(int n, int k) {
        string s="";
        generate(s,'u',n);
        sort(v.begin(), v.end());
        if(v.size()>=k)return v[k-1];
        return "";
    }
};