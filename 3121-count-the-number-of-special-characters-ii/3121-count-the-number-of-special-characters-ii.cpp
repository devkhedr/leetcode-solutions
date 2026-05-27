class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        for (char w = 'a'; w <= 'z'; w++) {
            char up = toupper(w);
            int lastLower = word.rfind(w);
            int firstUpper = word.find(up);
            if (lastLower != string::npos &&
                firstUpper != string::npos &&
                lastLower < firstUpper) {
                count++;
            }
        }
        return count;
    }
};