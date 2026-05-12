class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int need = 0;
        for (int i = tasks.size() - 1; i >= 0; i--) {
            int actual = tasks[i][0];
            int minimum = tasks[i][1];
            need = max(minimum, need + actual);
        }
        return need;
    }
};