class Solution {
public:
    int numberOfSubstrings(string s) {
        set<int> st[3];
        int n = s.size();
        for(int i=0;i<n;i++) {
            st[s[i] - 'a'].insert(i);
        }
        int ans = 0, idx1=-1, idx2=-1;
        for(int i=0;i<n;i++) {
            for(char a='a';a<='c';a++) {
                if(s[i] == a) continue;
                auto it = st[a-'a'].lower_bound(i);
                if(it == st[a-'a'].end()) continue;
                if(idx1 == -1) idx1 = *it;
                else idx2 = *it;
            }
            if(idx1 != -1 && idx2 != -1) {
                ans += n-max(idx1, idx2);
            }
            idx1 = idx2 = -1;
        }
        return ans;
    }
};