#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); // Initialize an empty n x n board
        vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
        backtrack(0, n, board, solutions, leftRow, upperDiag, lowerDiag);
        return solutions;
    }

private:
    void backtrack(int col, int n, vector<string>& board, vector<vector<string>>& solutions,
                   vector<int>& leftRow, vector<int>& upperDiag, vector<int>& lowerDiag) {
        if (col == n) {
            solutions.push_back(board);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (leftRow[row] == 0 && upperDiag[row + col] == 0 && lowerDiag[row - col + n - 1] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = upperDiag[row + col] = lowerDiag[row - col + n - 1] = 1;

                backtrack(col + 1, n, board, solutions, leftRow, upperDiag, lowerDiag);

                // Undo the current placement
                board[row][col] = '.';
                leftRow[row] = upperDiag[row + col] = lowerDiag[row - col + n - 1] = 0;
            }
        }
    }
};
