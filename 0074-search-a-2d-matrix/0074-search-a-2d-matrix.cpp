class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n*m-1, mid = 0, val = 0;
        while(low <= high) {
            mid = low + (high - low) / 2;
            val = matrix[mid/m][mid%m];
            if(val == target) return 1;
            if(val < target) low = mid + 1;
            else high = mid - 1;
        }
        return 0;
    }
};
