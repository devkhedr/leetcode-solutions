class Solution {
public:
    vector<string> res;
    bool check(string s)
    {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
                st.push('(');
            else if(s[i] == ')')
            {
                if(st.empty())
                    return 0;
                st.pop();
            }
        }
        return st.empty();
    }
    void rec(string s, int  n)
    {
        if(n == 0)
        {
            if(check(s))
                res.push_back(s);
            return;
        }
        rec(s + ')', n-1), rec(s+'(', n-1);
    } 
    vector<string> generateParenthesis(int n)
    {
        rec("(" , 2*n-1);
        return res;   
    }
};