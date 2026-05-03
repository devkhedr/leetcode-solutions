class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(s.size() != goal.size()) return 0;
        bool valid;
        for(int i=0;i<n;i++) {
            int idx = i;
            valid = 1;
            for(int j=0;j<n;j++) {
                if(goal[j] != s[idx%n]) valid = 0;
                idx++;
            }
            if (valid) return 1;
        }
        return 0;
    }
};