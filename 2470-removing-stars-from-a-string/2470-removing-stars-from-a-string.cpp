class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(char i: s) {
            if( i == '*') {
                if(!st.empty() && st.top() != '*')st.pop();
                else st.push(i);
            }
            else 
                st.push(i);
        }
        string t = "";
        while(!st.empty()) t += st.top(), st.pop();
        reverse(t.begin(), t.end());
        return t;
    }
};