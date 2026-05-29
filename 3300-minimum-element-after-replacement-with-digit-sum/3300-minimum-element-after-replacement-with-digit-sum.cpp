class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX, sum;
        for(int &x: nums) {
            sum = 0;
            while(x > 0) {
                sum += x%10;
                x/=10;
            }
            mn = min(mn, sum);
        }
        return mn;
    }
};