class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(),m = grid[0].size();
        int till = min(n , m) / 2;
        vector<vector<int>>ans(n , vector<int>(m));
        for(int offset = 0; offset < till; offset++){
            int tot = 2*n+2*m-4-8*offset;
            int shift = k % tot;
            int row = m - 2*offset,col = n - 2*offset;
            for(int i = 0; i < tot; i++){
                int curId = (i + tot - shift) % tot;
                int curx,cury,finx,finy;
                if(curId < row ){
                    finx = offset,finy = offset + curId;
                }
                else if(curId < (row + col - 2)){
                    finy = m - 1 - offset,finx = offset + (curId - row) + 1;
                }
                else if(curId < (2*row + col - 3)){
                    finx = n - 1 - offset,finy = m - 1 - offset - (curId - row - col + 2);
                }
                else{
                    finy = offset,finx = n - 1 - offset - (curId - 2*row - col + 3);
                }
                if(i < row ){
                    curx = offset,cury = offset + i;
                }
                else if(i < (row + col - 2)){
                    cury = m - 1 - offset,curx = offset + (i - row) + 1;
                }
                else if(i < (2*row + col - 3)){
                    curx = n - 1 - offset,cury = m - 1 - offset - (i - row - col + 2);
                }
                else{
                    cury = offset,curx = n - 1 - offset - (i - 2*row - col + 3);
                }
                ans[finx][finy] = grid[curx][cury];
            }
        }
        return ans;
    }
};