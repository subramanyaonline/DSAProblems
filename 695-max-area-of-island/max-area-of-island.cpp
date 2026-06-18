class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int,int>> q  ; 
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size())) ;
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}} ; 
        int areaOfMaxIsland = 0 ; 

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]){
                    q.push(make_pair(i,j)) ;
                    visited[i][j] = true ;
                    int area = 1 ; //area of the current cell which is 1. 
                    while(!q.empty()){
                        int x = q.front().first ;
                        int y = q.front().second ;
                        q.pop() ;
                        //you can do area++ here too. 
                        for(int k=0;k<directions.size();k++){
                            int nx = x + directions[k].first ;
                            int ny = y + directions[k].second ;
                            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && !visited[nx][ny] && grid[nx][ny]){
                                q.push(make_pair(nx,ny)) ;
                                visited[nx][ny] = true ;
                                area++; 
                            }
                        }
                    }
                    areaOfMaxIsland = max(areaOfMaxIsland,area) ; 
                }
            }
        }

        return areaOfMaxIsland ;
    }
};