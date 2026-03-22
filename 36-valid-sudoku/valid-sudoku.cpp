class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) { 
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(!isValidCell(board,i,j,board[i][j]) && board[i][j]!='.' ) return false ;
            }
        }
        return true ;
    }

    bool isValidCell(vector<vector<char>> &board, int row, int col, int k){
        //checing in the same row 
        for(int i=0;i<9;i++){
            if(i==col) continue ;
            if(board[row][i] == board[row][col]) return false ;
        }

        //checking in the same col 
        for(int i=0;i<9;i++){
            if(i==row)continue ;
            if(board[i][col] == board[row][col]) return false ;
        }

        //checking in the same grid. 
        int smallboxrow=(row/3)*3 ;  //innerbox starting index for row
        int smallboxcol=(col/3)*3 ; //innerbox starting index for col 
        for(int i=smallboxrow; i<smallboxrow+3;i++){
            for(int j=smallboxcol ; j<smallboxcol+3; j++){
                if(i==row && j==col) continue; 
                if(board[row][col] == board[i][j]) return false ;
            }
        }

        //this means the cell is valid 
        return true; 
    }
};