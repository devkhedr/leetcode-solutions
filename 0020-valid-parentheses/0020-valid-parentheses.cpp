class Solution {
public:
    bool isValid(string s) {
    
    stack<int>st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '[' || s[i] == '{' || s[i] == '(')
            st.push(s[i]);
        else 
        {
            if(st.empty())return 0;
            char cur = st.top();
            st.pop();
            if(s[i] == ')' && cur!='(')return false;
            else if(s[i] == '}' && cur!='{')return false;
            else if(s[i] == ']' && cur != '[')return false;
        }
    }        
    return st.empty();
}
};