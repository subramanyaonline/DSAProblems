class Solution {
public:
    int maxlen(vector<vector<int>> &matrix, vector<vector<int>> &visited, int i, int j){
        if(i<0 || j<0 || i==matrix.size() || j==matrix[0].size()) return 0 ;
        
        if(visited[i][j] != -1) return visited[i][j] ;
        
        int val = 0 ;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]) val = max(val,maxlen(matrix,visited,i-1,j)+1); 
        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]) val = max(val,maxlen(matrix,visited,i+1,j)+1) ;
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]) val = max(val,maxlen(matrix,visited,i,j-1)+1) ;
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]) val = max(val,maxlen(matrix,visited,i,j+1)+1) ;
        return visited[i][j] = val ; 
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> visited(
            matrix.size(),vector<int>(matrix[0].size(),-1)
        );  //here i will store max len that can be reached from cell i,j 

        int longestPath = 0 ; 
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(visited[i][j] == -1) visited[i][j] =  maxlen(matrix,visited,i,j);
                longestPath = max(longestPath,visited[i][j]) ;
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }

        return longestPath+1;        
    }
};