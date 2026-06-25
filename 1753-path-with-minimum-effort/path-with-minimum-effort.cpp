class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(); int n = heights[0].size(); 
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}} ; 
        vector<vector<int>> minEffort(m,vector<int>(n,INT_MAX)); 

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>> ,greater<tuple<int,int,int>>> pq ; 

        pq.push({0,0,0}); 
        minEffort[0][0] = 0 ; 

        while(!pq.empty()){
            auto [w,x,y] = pq.top();//w = max diff btw any two consective cells in path
            pq.pop(); 
            if(w>minEffort[x][y]) continue ; //else w = minEffort[x][y] , it will be . 

            for(int i=0;i<4;i++){
                int dx = x + dir[i].first ; 
                int dy = y + dir[i].second ; 
                if(dx<m && dy<n && dx>=0 && dy>=0){
                    int curreffort = abs(heights[x][y]-heights[dx][dy]) ; 
                    int patheffort = w ; 
                    int finaleffort = max(patheffort,curreffort) ; 

                    if(finaleffort < minEffort[dx][dy]){
                        minEffort[dx][dy] = finaleffort ; 
                        pq.push({finaleffort, dx, dy}); 
                    }
                }
            }
        }

        return minEffort[m-1][n-1] ; 
    }
};