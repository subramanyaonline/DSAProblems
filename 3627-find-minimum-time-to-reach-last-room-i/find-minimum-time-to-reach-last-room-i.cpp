class Solution {
public:
    struct tuple{
        int i ;
        int j ; 
        int t ; 
    }; 

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(); 
        int n = moveTime[0].size(); 
        vector<vector<long long>> minCost(m,vector<long long>(n,INT_MAX)); 
        queue<tuple> q ;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}}; 

        q.push({0,0,0}); 
        minCost[0][0] = 0 ; 

        while(!q.empty()){
            int x = q.front().i ; 
            int y = q.front().j ; 
            int t = q.front().t ; 
            q.pop(); 

            for(int i=0;i<4;i++){
                int dx = x + dir[i].first ; 
                int dy = y + dir[i].second ; 
                if(dx>=0 && dy>=0 && dx<m && dy<n){
                    int dt = max(t+1, moveTime[dx][dy]+1); 
                    if(dt<minCost[dx][dy]){
                        minCost[dx][dy] = dt ;
                        q.push({dx,dy,dt});  
                    }
                }
            }
        }

        return minCost[m-1][n-1] ; 
    }
};