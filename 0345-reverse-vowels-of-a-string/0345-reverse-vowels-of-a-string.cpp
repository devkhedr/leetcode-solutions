class Solution {
public:
    bool is_vowel(char c) {
        if(c <= 'Z') c+=32;
        return (c == 'a' or c == 'i' or c=='e' or c == 'o' or c == 'u');   
    }
    string reverseVowels(string s) {
        vector<int> idx;
        for(int i=0;i<s.length();i++) {
            if(is_vowel(s[i])) {
                idx.push_back(i);        
            }
        }
        int l = 0, r = idx.size() - 1;
        while(l < r) {
            swap(s[idx[l]], s[idx[r]]);
            l++, r--;
        }
        return s;
    }
};