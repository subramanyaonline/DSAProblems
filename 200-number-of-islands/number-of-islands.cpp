class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size())) ;
        queue<pair<int,int>> q ; 
        int noOfIslands = 0 ;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    noOfIslands++; 
                    q.push({i,j});
                    visited[i][j] = true ;
                    while(!q.empty()){
                        int x = q.front().first ;
                        int y = q.front().second ; 
                        q.pop(); 
                        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()) continue ;
                        if(x<grid.size()-1 && grid[x+1][y]=='1' &&!visited[x+1][y]) {
                            q.push({x+1,y}) ;
                            visited[x+1][y] = true ;
                        }
                        if(x>0 && grid[x-1][y]=='1' && !visited[x-1][y]) {
                            q.push({x-1,y}) ;
                            visited[x-1][y] = true ;
                        }
                        if(y>0 && grid[x][y-1]=='1' && !visited[x][y-1]) {
                            q.push({x,y-1}) ;
                            visited[x][y-1] = true ;
                        }
                        if(y<grid[0].size()-1 && grid[x][y+1]=='1' && !visited[x][y+1]) {
                            q.push({x,y+1}) ;
                            visited[x][y+1] = true ;
                        }
                    }
                }
            }
        }

        return noOfIslands ;
    }
};