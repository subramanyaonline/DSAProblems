class Solution {
public:

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(); int n = moveTime[0].size(); 
        vector<vector<int>> minCost(m,vector<int>(n,INT_MAX))     ; 
        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>> q ;   
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}}; 

        q.push({0,0,0,0});
        minCost[0][0] = 0 ; 

        while(!q.empty()){
            auto [currT,x,y,step] = q.top();
            q.pop(); 
            if(currT>minCost[x][y]) continue ; //stale entry --> other nodes have optimised mincost[][] , so this doesnot mean anything .
            if(x==m-1 && y==n-1) return currT ; 

            for(int i=0;i<4;i++){
                int dx = x + dir[i].first ; 
                int dy = y + dir[i].second ; 
                if(dx<m && dy<n && dx>=0 && dy>=0){
                    int ds = step==1 ? 2 : 1 ; 
                    int dt = max(currT+ds, moveTime[dx][dy]+ds) ;
                    if(minCost[dx][dy]>dt){
                        minCost[dx][dy] = dt ; 
                        q.push({dt,dx,dy,ds}); 
                    }
                }
            }          
        }
        return minCost[m-1][n-1] ; 
    }
};