class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> maxrow(grid.size()); 
        vector<int> maxcol(grid.size()) ; 

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                maxrow[i]=max(maxrow[i],grid[i][j]) ;
                maxcol[j]=max(maxcol[j],grid[i][j]) ;
            }
        }

        int tot = 0 ; 
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                tot += min(maxrow[i],maxcol[j])-grid[i][j] ;
                //cout<<min(maxrow[i],maxcol[j])<<" "; 
            }
        }

        return tot ;
    }
};