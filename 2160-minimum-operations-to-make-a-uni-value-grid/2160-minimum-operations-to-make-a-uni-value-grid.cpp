class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){  
                v.push_back(grid[i][j]);
            }
        }
        int ans=0;
        sort(v.begin(),v.end());
        int mid=v[v.size()/2];
        for(int i=0;i<v.size();i++){
            v[i]=abs(v[i]-mid);
            if(v[i]%x!=0){
                return -1;
            }
            ans+=v[i]/x;
        }
        return ans;
    }
};