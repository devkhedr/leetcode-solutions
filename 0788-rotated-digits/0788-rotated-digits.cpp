class Solution {
public:
    bool isGood(int n){
        vector<int> d(10,0);
        while(n > 0){
            d[n%10]++;
            n/=10;
        }
        if(d[7] or d[3] or d[4]) return false;
        return d[6] or d[9] or d[2] or d[5];
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n ; i++){
            if(isGood(i)) count++;
        }
        return count;
    }
};