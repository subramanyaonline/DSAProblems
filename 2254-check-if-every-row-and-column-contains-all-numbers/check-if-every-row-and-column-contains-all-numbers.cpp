class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(!isvalid(matrix,i,j,matrix[i][j])) return false; 
            }
        }
        return true ;
    }
    bool isvalid(vector<vector<int>> &matrix, int row,int col, int k){
        //checking same column
        for(int i=0;i<matrix.size();i++){
            if(i==row) continue; 
            if(matrix[i][col] == matrix[row][col]) return false ;
        }

        //checking same column 
        for(int i=0;i<matrix[0].size();i++){
            if(i==col) continue;  
            if(matrix[row][col] == matrix[row][i]) return false ;
        }

        return true; 
    }
};