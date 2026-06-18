class Solution {
public:
    void bfs(int i,int j, vector<vector<int>> &grid, vector<vector<int>> &visited){
        int m = grid.size(); 
        int n = grid[0].size() ;

        queue<pair<int,int>> q ; 
        vector<pair<int,int>> directions = {{0,-1},{0,1},{1,0},{-1,0}} ; 
        q.push(make_pair(i,j)) ;
        visited[i][j] = 0 ; //it is 0 by default, no problem 

        while(!q.empty()){
            pair<int,int> p = q.front() ; 
            q.pop(); 
            int parentTime = visited[p.first][p.second] ; 
            for(int i=0;i<directions.size();i++){
                int x = p.first + directions[i].first ;
                int y = p.second + directions[i].second ;
                if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1 && visited[x][y]>parentTime+1){
                    q.push({x,y}) ; 
                    visited[x][y] = parentTime + 1;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        vector<vector<int>> time(m,vector<int>(n,INT_MAX)) ;
        queue<int> q ; 

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    bfs(i,j,grid,time) ;
                }
            }
        }

        int minTimeRequired = 0 ; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue ;
                else if(grid[i][j]==1 && time[i][j]==INT_MAX) return -1 ; 
                else if(grid[i][j]==1)minTimeRequired = max(minTimeRequired,time[i][j]) ;
            }
        }

        return minTimeRequired ; 
    }
};