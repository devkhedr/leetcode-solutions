class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> f1(150), f2(150);
        for(char c: p) f1[c]++;
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        int l = 0, r = p.size()-1;
        for(int i=0;i<=r;i++) {
            f2[s[i]]++;
        }
        while(r < s.size()) {
            bool ok = 1;
            for(char a='a';a<='z';a++) {
                if(f1[a] != f2[a]) ok = 0;
            }
            if(ok) ans.push_back(l);
            if(l < s.size()) f2[s[l]]--;
            l++, r++;
            if(r < s.size()) f2[s[r]]++;
        }
        return ans;
    }
};