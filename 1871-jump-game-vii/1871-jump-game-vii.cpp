class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int n = s.size();
        vector<int> vis(n+1,0);
        q.push(0);
        int mxreach = 0;
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            if(idx == n-1){
                return true;
            }
            for(int i = (int)(max(mxreach,idx+minJump)); i<=(int)(min(idx+maxJump,n-1)); i++){
                if(vis[i] == 0 && s[i] == '0'){
                    q.push(i);
                    vis[i] = 1;
                }
            }
            mxreach = max(mxreach,idx+maxJump+1);
        }
        return false;
    }
};