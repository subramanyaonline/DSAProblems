class Solution {
public:

    bool bfs(vector<vector<int>>&grid, vector<vector<bool>>&visited , int i, int j){
        int m = grid.size() ; 
        int n = grid[0].size() ; 
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}}    ; 
        bool retval = true ;

        queue<pair<int,int>> q ; 
        q.push({i,j}) ; 
        visited[i][j] = true ;

        while(!q.empty()){
            auto p = q.front() ;
            int x = p.first ; 
            int y = p.second ;  
            q.pop() ; 

            for(int i=0;i<dir.size();++i){
                int dx = x + dir[i].first ; 
                int dy = y + dir[i].second ; 
                //cout<<dx<<" "<<dy<<endl ;
                if(dx<0 || dy<0 || dx>=m ||dy>=n) retval = false ;
                else if(!grid[dx][dy] && !visited[dx][dy]){
                    visited[dx][dy] = true ; 
                    //cout<<dx<<" "<<dy<<endl ;
                    q.push({dx,dy}) ; 
                }
            }
        }
        cout<<"returning "<<endl<<endl ;
        return retval ; 
    }


    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size() ; int n = grid[0].size() ; 
        vector<vector<bool>> visited(m,vector<bool>(n)) ; 
        int islands = 0 ; 
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && !grid[i][j]){
                    if(bfs(grid,visited,i,j)){
                        islands++ ; 
                        //cout<<i<<" "<<j<<endl ;
                    } 
                }
            }
        }

        return islands ; 
    }
};