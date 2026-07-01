class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = grid.size(); 
        vector<vector<int>> dp(n+2,vector<int>(n+2,800)) ; //stores minlen btw cells and theifcells

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(grid[i-1][j-1]) dp[i][j] = 0 ; 
                else dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1 ; 
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=n;j>=1;j--){
                if(grid[i-1][j-1]) dp[i][j] = 0 ; 
                else dp[i][j] = min(dp[i][j],min(dp[i+1][j],dp[i][j+1])+1) ; 
            }
        }

        priority_queue<tuple<int,int,int>> pq ; //
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}} ; 
        vector<vector<int>> maxDist(n,vector<int>(n,-1)) ; 

        pq.push({dp[1][1],0,0}) ; 
        maxDist[0][0] = dp[1][1] ; 

        while(!pq.empty()){
            auto [safeness,x,y] = pq.top() ; 
            pq.pop() ; 
            //cout<<x<<" "<<y ; 
            if(maxDist[x][y]>safeness) continue ; 
            if(x==n-1 && y==n-1) return safeness ; 

            for(int i=0;i<4;i++){
                int dx = dir[i].first + x ; 
                int dy = dir[i].second + y ; 

                if(dx<n && dy<n && dx>=0 && dy>=0){
                    
                    int currSafeness = min(dp[dx+1][dy+1],safeness) ;
                    if(currSafeness>maxDist[dx][dy]){
                        pq.push({currSafeness,dx,dy}) ; 
                        maxDist[dx][dy] = currSafeness ;
                    } 

                }

            }
        }
        return maxDist[n-1][n-1] ; 
    }
};