class Solution {
public:
    int binaryGap(int n) {
        int mx = 0, cnt = 0, found = 0;
        while(n > 0) {
            int val = n%2;
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