class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        vector<bool> vis(arr.size());
        q.push(start);
        bool ok = 0;
        while(!q.empty()) {
            int x = q.front();
            if(arr[x] == 0) {
                ok = 1;
                break;
            }
            q.pop();
            if(x+arr[x] < arr.size() &&!vis[x+arr[x]]) q.push(x+arr[x]), vis[x+arr[x]] = 1;
            if(x-arr[x] >= 0 && !vis[x-arr[x]]) q.push(x-arr[x]), vis[x-arr[x]] = 1;
        }
        return ok;
    }
};