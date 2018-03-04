class Solution {
public:
    bool win(vector<string>& board, char c) {
        for (int i = 0; i < 3; ++i) {
            bool winG = true;
            for (int j = 0; j < 3; ++j) {
                winG = winG && (board[i][j] == c);
            }
            if (winG) return true;
        }
        for (int j = 0; j < 3; ++j) {
            bool winG = true;
            for (int i = 0; i < 3; ++i) {
                winG = winG && (board[i][j] == c);
            }
            if (winG) return true;
        }
        bool winG = true;
        for (int i = 0; i < 3; ++i) {
            winG = winG && (board[i][i] == c);
        }
        if (winG) return true;
        winG = true;
        for (int i = 0; i < 3; ++i) {
            winG = winG && (board[2 - i][i] == c);
        }
        if (winG) return true;
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int xCnt = 0, oCnt = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') ++xCnt;
                else if (board[i][j] == 'O') ++oCnt;
            }
        }
        if (oCnt > xCnt || xCnt > oCnt + 1)
            return false;
        bool xWin = win(board, 'X');
        bool oWin = win(board, 'O');
        if (xWin && oWin) return false;
        if (xWin && xCnt != oCnt + 1) return false;
        if (oWin && xCnt != oCnt) return false;
        return true;
    }
};