class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size(); 
        int n = grid[0].size(); 

        if(grid[m-1][n-1]||grid[0][0]) return -1 ; 
        vector<vector<bool>> visited(m,vector<bool>(n)); 

        queue<pair<int,int>> q ;
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1}}; 

        q.push({0,0}); 
        visited[0][0] = true ;
        int pathlen = 1 ; 

//Level Order BFS , you can also use marker insertion(null) , need to be careful 
        while(!q.empty()){
            int size = q.size() ; 
    
            while(size--){
                int x = q.front().first ;
                int y = q.front().second ;
                q.pop(); 
                
                if(x == m-1 && y == n-1)
                    return pathlen;
                
                
                for(int i=0;i<8;i++){
                    int dx = x + directions[i].first ; 
                    int dy = y + directions[i].second ; 
                    if(dx<m && dy<n && dx>=0 && dy>=0 && !visited[dx][dy] && !grid[dx][dy]){
                        q.push({dx,dy}); 
                        visited[dx][dy] = true ;
                    }
                }
            }
            pathlen++; 
        }
        if(!visited[m-1][n-1]) return -1 ; 
        return pathlen ;
    }
};