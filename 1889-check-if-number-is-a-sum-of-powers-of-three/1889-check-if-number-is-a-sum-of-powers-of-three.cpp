class Solution {
public:
    bool checkPowersOfThree(int n) {
        int number_of_bits = 15;
        vector<long long> power_of_three(16);
        power_of_three[0] = 1;
        for(int i=1;i<=number_of_bits;i++) {
            power_of_three[i] = power_of_three[i-1]*3;
        }
        for(long long mask = 0;mask < (1LL << number_of_bits); mask++) {
            long long sum = 0;
            for(int i=0;i<number_of_bits;i++) {
                if(mask&(1LL<<i))
                    sum += power_of_three[i];
            }
            if(sum == n) return true;
        }
        return false;
    }
};