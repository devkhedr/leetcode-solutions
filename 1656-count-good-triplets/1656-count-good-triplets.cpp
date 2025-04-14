class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0, n = arr.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    cnt += (abs(arr[i] - arr[j]) <= a and abs(arr[j]-arr[k])<=b and abs(arr[i]-arr[k]) <=c);
                }
            }
        }
        return cnt;
    }
};