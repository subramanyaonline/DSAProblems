class Solution {
public:
    bool ifSurrounded(int i, int j , vector<vector<char>> &board, vector<vector<bool>> &visited){
        if(i>=board.size()||i<0||j<0||j>=board[0].size()) return false ;
        if(board[i][j]=='X' || visited[i][j]) return true ;

        visited[i][j] = true; 

        bool down = ifSurrounded(i + 1, j, board, visited);
        bool up = ifSurrounded(i - 1, j, board, visited);
        bool right = ifSurrounded(i, j + 1, board, visited);
        bool left = ifSurrounded(i, j - 1, board, visited);

        return down && up && right && left;
    }

    void change(int i, int j, vector<vector<char>> &board){
        if(i>=board.size()||i<0||j<0||j>=board[0].size()||board[i][j]=='X')return ;
        board[i][j] = 'X' ;
        change(i+1,j,board) ;
        change(i,j+1,board) ; 
        change(i,j-1,board) ;
        change(i-1,j,board) ; 
        return ;
    }


    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size())) ;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    if(ifSurrounded(i,j,board,visited)){
                        change(i,j,board) ; 
                    }
                }
            }
        }
    }
};
