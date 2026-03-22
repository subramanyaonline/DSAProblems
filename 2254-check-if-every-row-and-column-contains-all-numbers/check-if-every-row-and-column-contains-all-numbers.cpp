class Solution {
public:
    bool checkValid(vector<vector<int>>&matrix){
        int n = matrix.size() ;
        //finding sum of row and col would not work as 2 2 2 2 in 2x2 matrix. 
        unordered_set<int> s; 
        for(int i = 1 ;i<=n;i++) s.insert(i) ;
        
        for(int i=0;i<n;i++){
            unordered_set<int> rowset ;
            unordered_set<int> colset ;
            for(int j=0;j<n;j++){
                rowset.insert(matrix[i][j]) ;
                colset.insert(matrix[j][i]) ;
            }
            if(rowset != s) return false ; 
            if(colset != s) return false ;
        }

        return true ; 
    }  
};

// bool checkValid(vector<vector<int>>& matrix) {
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(!isvalid(matrix,i,j,matrix[i][j])) return false; 
//             }
//         }
//         return true ;
//     }
//     bool isvalid(vector<vector<int>> &matrix, int row,int col, int k){
//         //checking same column
//         for(int i=0;i<matrix.size();i++){
//             if(i==row) continue; 
//             if(matrix[i][col] == matrix[row][col]) return false ;
//         }

//         //checking same column 
//         for(int i=0;i<matrix[0].size();i++){
//             if(i==col) continue;  
//             if(matrix[row][col] == matrix[row][i]) return false ;
//         }

//         return true; 
//     }