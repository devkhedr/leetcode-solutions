class Solution {
public:
    int binaryGap(int n) {
        int val = 0, mx = 0, cnt = 0;
        bool found = 0;
        while(n > 0) {
            val = n%2;
            if(!val) cnt++;
            else {
                if(found) mx = max(mx, cnt+1);
                cnt = 0, found = 1;
            }
            n/=2;
        }      
        return mx;
    }
};