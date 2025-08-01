class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p(numRows);
        p[0] = {1};
        if(numRows == 1) return p;
        p[1] = {1,1};
        for(int i=2;i<numRows;i++) {
            p[i].resize(p[i-1].size()+1);
            p[i][0] = p[i].back() = 1;
            for(int j=1;j<p[i].size()-1;j++) {
                p[i][j] = p[i-1][j-1]+p[i-1][j];
            }
        }
        return p;
    }
};