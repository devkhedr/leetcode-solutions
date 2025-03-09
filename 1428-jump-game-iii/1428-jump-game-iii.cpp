class Solution {
public:
    bool vis[100001];  
    int solve(int i, vector<int> &arr) {
        if(!arr[i]) return 1;
        vis[i] = 1;
        int mx = 0;
        if(i+arr[i] < arr.size() && !vis[i+arr[i]]) mx = max(mx, solve(i+arr[i], arr) );
        if(i-arr[i] >= 0 && !vis[i-arr[i]]) mx = max(mx, solve(i-arr[i], arr));
        return mx;
    }
    bool canReach(vector<int>& arr, int start) {
        return solve(start, arr);
    }
};