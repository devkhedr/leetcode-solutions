class Solution {
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int, vector<int>> port;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            for (int d = 2; d * d <= tmp; d++) {
                if (tmp % d == 0) {
                    port[d].push_back(i);
                    while (tmp % d == 0) {
                        tmp /= d;
                    }
                }
            }

            if (tmp > 1) {
                port[tmp].push_back(i);
            }

        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front();
                q.pop();
                int num = nums[i];
                if (visited[i]) 
                    continue;
                visited[i] = true;
                if (i == n - 1) 
                    return steps;
                if (port.count(num)) {
                    for (int nei : port[num]) {
                        q.push(nei);
                    }
                    port.erase(num);
                }
                if (i + 1 < n) {
                    q.push(i + 1);
                }
                if (i - 1 >= 0) {
                    q.push(i - 1);
                }
            }
            steps++;
        }
        return steps;
    }
};