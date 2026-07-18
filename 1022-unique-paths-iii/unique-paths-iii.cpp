class Solution {
public:
    int findpaths(vector<vector<int>>& grid, int rowidx, int colidx, vector<vector<bool>> &visited, int no){
        if(rowidx<0|| rowidx>=grid.size() || colidx<0 || colidx>=grid[0].size() )
            return 0 ; 
        if(grid[rowidx][colidx]==2 && !no) return 1 ; 
        if(grid[rowidx][colidx]==2) return 0 ; // not all empty cells in the grid are visited . or 
        if(visited[rowidx][colidx] ||  grid[rowidx][colidx]==-1) return 0 ; 
        
        //cout<<"hello"<<endl; 
        visited[rowidx][colidx] = true ;
        int delta = grid[rowidx][colidx]==1 ? 0 : 1 ;  
        int paths =  
        findpaths(grid,rowidx+1,colidx,visited , no-delta) + 
        findpaths(grid,rowidx-1,colidx,visited , no-delta) +
        findpaths(grid,rowidx,colidx+1,visited , no-delta) +
        findpaths(grid,rowidx,colidx-1,visited , no-delta) ; 
    
        visited[rowidx][colidx] = false ; 
         
        return paths ; 
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size())) ;
        int noofemptycells = 0 ; 
        int startrow, startcol ; 

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();++j){
                if(!grid[i][j]) noofemptycells++ ;
                else if(grid[i][j]==1) {
                    startrow = i ; 
                    startcol =  j ; 
                } 
            }
        }

        //visited[startrow][startcol] = true ; 
        //cout<<startrow<<" "<<startcol<<endl ; 
        return findpaths(grid,startrow,startcol,visited,noofemptycells) ; 

    }
};