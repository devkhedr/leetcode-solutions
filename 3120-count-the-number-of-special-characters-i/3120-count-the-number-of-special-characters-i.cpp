class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size(), cnt = 0;
        for(char x='a';x<='z';x++) {
            cnt +=  (word.find(x)<n and word.find(x-32) < n);
        }
        return cnt;
    }
};