class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size())) ;
        int noOfIslands = 0 ; 
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}} ;
        queue<pair<int,int>> q ;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    noOfIslands++ ;
                    visited[i][j] = true ;
                    q.push(make_pair(i,j)) ; 

                    while(!q.empty()){

                        int x = q.front().first ;
                        int y = q.front().second ;
                        q.pop() ;

                        for(pair<int,int> p : directions){
                            int dx = p.first + x ;
                            int dy = p.second + y ;
                            if(dx>=0&&dx<grid.size()&&dy>=0&&dy<grid[0].size()&&!visited[dx][dy]&&grid[dx][dy]=='1'){
                                q.push(make_pair(dx,dy)) ;
                                visited[dx][dy] = true ;
                            }
                           
                        }

                    }

                }
            }
        }
        return noOfIslands ;
    }
}; 