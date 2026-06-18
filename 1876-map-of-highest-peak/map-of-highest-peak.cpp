class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(); 
        int n = isWater[0].size(); 
        vector<vector<int>> matrix(m,vector<int>(n)); 
        queue<pair<int,int>> q ;
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){
                    q.push({i,j});
                    //cout<<"pushed"<<endl; 
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first ;
            int y = q.front().second ;
            q.pop(); 
            //cout<<"popped" <<endl ; 

            for(int i=0;i<4;i++){
                int dx = x + dir[i].first ;
                int dy = y + dir[i].second ; 
                if(dx>=0 && dy>=0 && dx<m && dy<n && !matrix[dx][dy] && !isWater[dx][dy]){
                    q.push({dx,dy}) ; 
                    matrix[dx][dy] = matrix[x][y]+1 ;
                }
            }
        }
        return matrix ;
    }
};