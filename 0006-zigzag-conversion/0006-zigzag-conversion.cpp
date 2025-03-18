class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        int n = s.size();
        
        vector<string> rows(min(numRows,n));
        int r = 0;
        bool down = true;
        
        for(char c : s){
            rows[r] += c;
            r += down ? 1 : -1;
            if(r == 0 || r == numRows-1)
                down = !down;
        }
        
        string ans;
        for(string& row : rows){
            ans += row;
        }
        return ans;
    }
};