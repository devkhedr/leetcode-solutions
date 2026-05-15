class Solution {
public:
    int n;
    inline int findK(vector<int>& x) {
        if (n==1) return 0;
        if (n==2) return (x[0]<x[1])?1:0;
        int l=0, r=n, m;
        while(l<r){
            m=(r+l)/2;
            if (m==n-1 || x[m]>x[m+1]) return m;
            if (x[m]>x[l]) l=m;
            else r=m;    
        }
        return m;
    }
    int findMin(vector<int>& nums) {
        n=nums.size();
        return nums[(findK(nums)+1)%n];
    }
};