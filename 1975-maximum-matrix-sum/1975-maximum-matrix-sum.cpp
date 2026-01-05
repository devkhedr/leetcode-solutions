class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0, cnt = 0, mn = INT_MAX, n = matrix.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cnt += (matrix[i][j]<0);
                sum += abs(matrix[i][j]);
                mn = min(mn, abs((long long)(matrix[i][j])));
            }
        }
        if(cnt & 1) sum -= 2*mn;
        return sum;
    }
};