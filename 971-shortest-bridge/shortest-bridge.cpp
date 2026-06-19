class Solution {
public:
    queue<pair<int,int>> bfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &firstIsland, queue<pair<int,int>> &q,vector<pair<int,int>> &directions){
        queue<pair<int,int>> returnQueue ;
        q.push({i,j}); 
        firstIsland[i][j] = true ;
        while(!q.empty()){
            int x = q.front().first ;
            int y = q.front().second ; 
            q.pop(); 
            returnQueue.push({x,y}); 

            for(int i=0;i<4;i++){
                int nx = x + directions[i].first ; 
                int ny = y + directions[i].second ; 
                if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && !firstIsland[nx][ny] && grid[nx][ny]==1){
                    q.push({nx,ny}); 
                    firstIsland[nx][ny] = true ;
                }

            }
            
        }
        cout<<returnQueue.size(); 
        return returnQueue ;
    }

    int searchForSecondIsland(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &firstIsland, queue<pair<int,int>> &q,vector<pair<int,int>> &directions){
        int pathlen = 0 ;
        while(!q.empty()){

            int size = q.size(); 
            //cout<<"size:"<<size<<endl; 
            while(size--){
                int x = q.front().first ; 
                int y = q.front().second ;
                q.pop();
                
                for(int i=0;i<directions.size();i++){
                    int nx = x + directions[i].first ; 
                    int ny = y + directions[i].second ; 
                    if(nx<grid.size() && ny<grid[0].size() && nx>=0 && ny>=0 && !firstIsland[nx][ny]){
                        q.push({nx,ny}); 
                        firstIsland[nx][ny] = true ;
                        if(grid[nx][ny]) return pathlen ;
                    }
                }
            }
            pathlen++; 
        }
        return pathlen ; 
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        vector<vector<bool>> firstIsland(m,vector<bool>(n)); 
        vector<vector<bool>> secondIsland(m,vector<bool>(n));
        queue<pair<int,int>> q ; 
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}}; 

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q = bfs(i,j,grid,firstIsland,q,directions);
                    return searchForSecondIsland(i,j,grid,firstIsland,q,directions); 
                }
            }
        }
        return -1 ; 
    }
};