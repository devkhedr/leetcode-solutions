class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int maxVowels(string s, int k) {
        int l = 0, r = k-1, cnt = 0, n = s.size(); 
        for(int i=l;i<=r;i++) {
            if(isVowel(s[i]))cnt++;
        }      
        int mx = 0;
        while(r < n) {
            mx = max(mx, cnt);
            r++; 
            if(r < n) cnt += isVowel(s[r]);
            cnt -= isVowel(s[l]), l++;
        }
        return mx;
    }
};