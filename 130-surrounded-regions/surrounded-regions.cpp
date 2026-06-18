class Solution {
public:
    bool ifSurrounded(int i, int j, vector<vector<char>>& board,
                      vector<vector<bool>>& visited) {

        // Went outside ⇒ region touches boundary
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;

        // X acts as a wall
        if (board[i][j] == 'X')
            return true;

        // Already explored during this DFS
        if (visited[i][j])
            return true;

        visited[i][j] = true;

        bool down = ifSurrounded(i + 1, j, board, visited);
        bool up = ifSurrounded(i - 1, j, board, visited);
        bool right = ifSurrounded(i, j + 1, board, visited);
        bool left = ifSurrounded(i, j - 1, board, visited);

        return down && up && right && left;
    }

    void change(int i, int j, vector<vector<char>>& board) {

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
            board[i][j] == 'X')
            return;

        board[i][j] = 'X';

        change(i + 1, j, board);
        change(i - 1, j, board);
        change(i, j + 1, board);
        change(i, j - 1, board);
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Process each component only once
                if (board[i][j] == 'O' && !visited[i][j]) {

                    if (ifSurrounded(i, j, board, visited)) {
                        change(i, j, board);
                    }
                }
            }
        }
    }
};