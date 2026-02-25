class Solution {
public:
    static int count1(int n) {
        int cnt = 0;
        while(n>0) {
            cnt += (n%2);
            n/=2;
        } return cnt;
    }
    static bool cmp(int &x, int &y) {
        int a = count1(x), b = count1(y);
        if(a == b) return x < y;
        return a < b;
    }   
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};