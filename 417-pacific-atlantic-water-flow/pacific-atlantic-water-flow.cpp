class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); 
        int n = heights[0].size(); 
        vector<vector<int>> visited(m,vector<int>(n)); 
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q; 
        vector<vector<int>> ans ;

        //traversing all the indices from which water gets to pacific ocean 
        for(int i=0;i<m;i++){
            q.push({i,0});
            visited[i][0] = 1 ; 
        }
        for(int j=1;j<n;j++){
            q.push({0,j});
            visited[0][j] = 1 ;
        }
        while(!q.empty()){
            int x = q.front().first; 
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx = x + dir[i].first ;
                int dy = y + dir[i].second; 
                if(dx<m && dy<n && dx>=0 && dy>=0 && !visited[dx][dy] && heights[x][y]<=heights[dx][dy]){
                    q.push({dx,dy}); 
                    visited[dx][dy] = 1 ;
                }
            } 
        }

        //traversing to all cells from which water flows to the atlantic ocean . 
        for(int i=0;i<m;i++){
            q.push({i,n-1});
            if(visited[i][n-1]) ans.push_back({i,n-1}); 
            visited[i][n-1]= 2 ;
        }
        for(int j=0;j<n-1;j++){
            q.push({m-1,j});
            if(visited[m-1][j]) ans.push_back({m-1,j});
            visited[m-1][j] = 2 ;
        }
        while(!q.empty()){
            int x = q.front().first ; 
            int y = q.front().second ;
            q.pop(); 
            for(int i=0;i<dir.size();i++){
                int dx = x + dir[i].first ;
                int dy = y + dir[i].second ;
                if(dx<m && dy<n && dx>=0 && dy>=0 && heights[x][y]<=heights[dx][dy] && visited[dx][dy]!=2){
                    q.push({dx,dy}); 
                    if(visited[dx][dy]) ans.push_back({dx,dy}); 
                    visited[dx][dy]= 2 ;
                }
            }
        }

        return ans ;
    }
};