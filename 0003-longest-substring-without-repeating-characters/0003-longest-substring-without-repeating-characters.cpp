class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int>st;
        int n = s.length(), mx = 0;
        for(int i=0;i<n;i++)
        {
            int j = i;
            st.clear();
            for(int j=i;j<n;j++)
            {
                st.insert(s[j]);
                if(st.size() == j-i+1)
                    mx = max(mx, j-i+1);
                else
                    break;
            }
        }
        return mx;
    }
};