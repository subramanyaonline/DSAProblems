class Solution {
public:
    struct tuple{
        int i ; 
        int j ; 
        int r ; 
    }; 

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(); 
        int n = grid[0].size(); 

        vector<vector<vector<bool>>> visited(m,
        vector<vector<bool>>(n,
        vector<bool>(k+1)
        )); 

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,-1},{0,1}}; 
        queue<tuple> q; 
        q.push({0,0,k}); //k obstacles can still be encountered . 
        visited[0][0][k] = true ;

        int minpathlen = 0 ; 
        while(!q.empty()){

            int size = q.size(); 
            while(size--){

                int x = q.front().i ;
                int y = q.front().j ;
                int r = q.front().r ;
                q.pop(); 

                if(x==m-1 && n-1==y) return minpathlen ; 

                for(int i=0;i<dir.size();i++){
                    int dx = x + dir[i].first ; 
                    int dy = y + dir[i].second ; 
                    if(dx<m && dy<n && dx>=0 && dy>=0){
                        int nr = r - grid[dx][dy]; // decrement only if obstacle
                        if(nr < 0 || visited[dx][dy][nr]) continue;
                        visited[dx][dy][nr] = true;
                        q.push({dx, dy, nr}); 
                        
                    }
                        
                }
            }
            minpathlen++;      
        }
        return -1 ; 
    }
};