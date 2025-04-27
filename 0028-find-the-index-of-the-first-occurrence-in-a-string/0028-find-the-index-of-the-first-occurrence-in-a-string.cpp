class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz1 = haystack.size(), sz2 = needle.size();
        for(int i=0;i<=sz1 - sz2;i++) {
            if(haystack.substr(i, sz2) == needle) return i;
        } return -1;
    }
};