#include <iostream>
#include <vector>

using namespace std;

bool is_valid(vector<vector<int>> &board, int r, int c, int num) {
    for (int i = 0; i < 9; ++i)
        if (board[r][i] == num || board[i][c] == num)
            return false;

    int sr = (r / 3) * 3, sc = (c / 3) * 3;
    for (int i = sr; i < sr + 3; ++i)
        for (int j = sc; j < sc + 3; ++j)
            if (board[i][j] == num) return false;

    return true;
}

bool solve(vector<vector<int>> &board) {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (is_valid(board, r, c, num)) {
                        board[r][c] = num;
                        if (solve(board)) return true;
                        board[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> board(9, vector<int>(9));
    cout << "Enter Sudoku (0 for blanks):\n";
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    if (solve(board)) {
        for (auto &row : board) {
            for (int x : row) cout << x << " ";
            cout << "\n";
        }
    } else {
        cout << "No solution.\n";
    }

    return 0;
}
