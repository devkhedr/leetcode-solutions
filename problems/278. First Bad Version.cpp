// Author: Mohamed Khedr

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, sol = 0, mid; 
        // we guarantee that all the numbers after the bad number are also bad
        // so if the mid value is bad -> we can store it and try another number less than it.
        while(l <= r) {
            mid = l+(r - l) / 2;
            if(isBadVersion(mid)) sol = mid, r = mid - 1;
            else l = mid + 1;
        }
        return sol;
    }
};