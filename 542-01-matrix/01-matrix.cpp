class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q ; 
        int ones = 0 ;
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size())); 
        vector<int> dr = {1,-1,0,0}; 
        vector<int> dc = {0,0,-1,1} ;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]) ones++; 
                else q.push({i,j}) ;
            }
        }

        while(!q.empty()){
            pair<int,int> p = q.front(); 
            int dist = ans[p.first][p.second] ;
            q.pop(); 
            for(int i=0;i<4;i++){
                int x = p.first + dr[i]; 
                int y = p.second  + dc[i] ; 
                if(x>=0 && y>=0 && x<mat.size() && y<mat[0].size() && mat[x][y] && !ans[x][y]){
                    ans[x][y] = dist + 1; 
                    ones--; 
                    q.push({x,y}) ;
                }
            }
        }

        return ans ;
    }
};