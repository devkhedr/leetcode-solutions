class Solution {
public:
    int n;
    string res1, res2;
    bool palindrome(string t)
    {
        string g = t;
        reverse(g.begin(), g.end());
        return (g == t);
    }
    bool check(int  mid, string s, int cur)
    {
        int l =0 , r = mid -1 ;
        while(r<n)
        {
            string t = s.substr(l, mid);
            if(palindrome(t))
            {
                if(cur == 1)
                    res1 = t;
                else 
                    res2 = t;
                return 1;
            }
            l++ , r++;
        }
        return 0;
    }
    string longestPalindrome(string s) {
        n = s.length();
        vector<int>od,ev; 
        for(int i=1;i<=n;i++)
        {
            if(i&1)od.push_back(i);
            else ev.push_back(i);
        }
        // binary search on odd, same with even
        int sol1 = 1, sol2 = 1;
        int l = 0, r = od.size() - 1, mid;
        while(l<=r)
        {
            mid = (l+r)>>1;
            if(check(od[mid], s, 1))
                l = mid+1;
            else 
                r = mid - 1;
        }
        l = 0, r= ev.size() -1;
        while(l<=r)
        {
            mid = (l+r)>>1;
            if(check(ev[mid], s, 2))
                l = mid + 1;
            else
                r = mid - 1;
        }
        if(res1.size()>=res2.size())
            return res1;
        else
            return res2;
    }
};