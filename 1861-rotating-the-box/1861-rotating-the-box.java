class Solution {
    public char[][] rotateTheBox(char[][] boxGrid) {
        int m=boxGrid.length;
        int n=boxGrid[0].length;
        char[][] ans=new char[n][m];
        for(char rows[]: ans){
            Arrays.fill(rows,'.');
        }
        for(int i=0;i<m;i++){
            int col=m-i-1;
            int top=n-1;
            int j=n-1;
            while(j>=0){
                if(boxGrid[i][j]=='#'){
                    ans[top][col]='#';
                    top--;
                }
                if(boxGrid[i][j]=='*'){
                    top=j;
                    ans[top][col]='*';
                    top--;
                }
                j--;
            }
        }
        return ans;
    }
}