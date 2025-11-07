#include <iostream>
#include <vector>

using namespace std;

class NQueens {
   public:
    NQueens(int n) : n(n), board(vector<vector<int>>(n, vector<int>(n, 0))) {}

    void solve() {
        if (placeQueens(0)) {
            printBoard();
        } else {
            cout << "No solution exists for " << n << " queens." << endl;
        }
    }

   private:
    int n;
    vector<vector<int>> board;

    bool isSafe(int row, int col) {
        // left row side
        for (int i = 0; i < col; ++i) {
            if (board[row][i] == 1) {
                return false;
            }
        }

        // upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // lower left diagonal
        for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    bool placeQueens(int col) {
        if (col >= n) {
            return true;
        }

        for (int i = 0; i < n; ++i) {
            if (isSafe(i, col)) {
                board[i][col] = 1;

                if (placeQueens(col + 1)) {
                    return true;
                }

                board[i][col] = 0;  // backtrack
            }
        }

        return false;
    }

    void printBoard() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << (board[i][j] == 1 ? "Q " : ". ");
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    NQueens nq(n);
    nq.solve();

    return 0;
}
