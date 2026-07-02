class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() ;
        int n = grid[0].size() ; 
        vector<vector<int>> cost(m,vector<int>(n,-1)) ; 
        priority_queue<tuple<int,int,int>> pq ; 
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}} ;

        int starthealth = grid[0][0]==1 ? health-1 : health ; 
        pq.push({starthealth,0,0})  ; 
        cost[0][0] = starthealth ; 

        while(!pq.empty()){

            auto [prevhealth,x,y] = pq.top() ; 
            pq.pop() ; 
            if(cost[x][y]>prevhealth) continue ; 
            if(x==m-1 && y==n-1) return true ; 

            for(int i=0;i<directions.size();i++){
                int dx = x + directions[i].first ; 
                int dy = y + directions[i].second ; 
                if(dx>=0 && dy>=0 && dx<m && dy<n){

                    if(grid[dx][dy] && prevhealth>1 && cost[dx][dy]<prevhealth-1){
                        pq.push({prevhealth-1,dx,dy}) ; 
                        cost[dx][dy] = prevhealth-1 ; 
                    }else if(!grid[dx][dy] && prevhealth>=1 && cost[dx][dy]<prevhealth){
                        pq.push({prevhealth,dx,dy}) ; 
                        cost[dx][dy] = prevhealth ; 
                    }

                    
                }
            }
            
        }

        return false ; 
    }
};