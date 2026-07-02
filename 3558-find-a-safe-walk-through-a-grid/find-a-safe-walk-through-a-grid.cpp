class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() , n = grid[0].size()  ;
        vector<vector<vector<int>>> cost(m,vector<vector<int>>(n,vector<int>(health,-1))); 
        priority_queue<tuple<int,int,int>> pq ; 
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}} ; 

        int starthealth = grid[0][0]==1 ? health-2 : health-1 ; 
        if(starthealth<0) return false ; 
        pq.push({starthealth,0,0});  
        cost[0][0][starthealth] = starthealth ; 

        while(!pq.empty()){
            auto [healthleft,x,y] = pq.top() ; 
            pq.pop() ;
            if(x==m-1 && y==n-1) return true ; 
            if(cost[x][y][healthleft] > healthleft) continue; 
            //cout<<healthleft<<"  "<<x<<"  "<<y <<endl ; 
            
            for(int i=0;i<directions.size();i++){
                int dx = x + directions[i].first ; 
                int dy = y + directions[i].second ; 
                if(dx<m && dy<n && dx>=0 && dy>=0){
                    //cout<<cost[x][y][healthleft]<<endl; 
                    //cout<<healthleft<<endl ;
                    if(grid[dx][dy] && healthleft>0 && cost[dx][dy][healthleft-1]<cost[x][y][healthleft] - 1 ){
                        //cout<<"inner"<<endl ; 
                        int curcost = cost[x][y][healthleft] - 1 ;
                        pq.push({curcost,dx,dy}) ; 
                        cost[dx][dy][healthleft-1] = curcost ; 
                    }else if(!grid[dx][dy] && healthleft>=0 && cost[dx][dy][healthleft]<cost[x][y][healthleft] ){
                        pq.push({healthleft,dx,dy}) ;
                        cost[dx][dy][healthleft] = cost[x][y][healthleft] ; 
                    }
                }
            }
        }

        return false ; 

    }
};