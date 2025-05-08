class Solution {
public:
typedef pair<int,pair<int,int>> p;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        int newTime =0;
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        priority_queue<p,vector<p>,greater<p>> pq;
        result[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            int i =cell.first;
            int j = cell.second;
            pq.pop();
            if(i == n-1 && j == m-1){
                return currTime;
            }
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int dir = 0;dir<4;dir++){
                int newr = i + dr[dir];
                int newc = j + dc[dir];
                if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                    int wait = max(moveTime[newr][newc] - currTime,0);
                    if(((i + j) % 2) == 0){
                     newTime = currTime + wait + 1;
                    }
                    else{
                         newTime = currTime + wait + 2;
                    }
                    if(result[newr][newc] > newTime){
                        result[newr][newc] = newTime;
                        pq.push({newTime,{newr,newc}});
                    }
                }
            }
        }
        return -1;
    }
};