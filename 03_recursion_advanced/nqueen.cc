// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

const int DIM = 10;

void setBoard(char board[][DIM], int N){
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < N; ++c){
            board[r][c] = 'X';
        }
    }
}

void printBoard(char board[][DIM], int N){
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < N; ++c){
          cout << board[r][c];  
        }
        cout << endl;
    }
}

bool check(char board[][DIM], int r, int c, int n) {

    for (int x = 0; x < n; ++x) {
        if (board[r][x] == 'Q') return false;
        if (board[x][c] == 'Q') return false;
    }

    int rowDir[] = { -1, -1, +1, +1};
    int colDir[] = { -1, +1, -1, +1};

    for (int d = 0; d < n; ++d) {
        for (int dir = 0; dir < 4; ++dir) {
            int rowCord = r + rowDir[dir] * d;
            int colCord = c + colDir[dir] * d;

            if (rowCord >= 0 && rowCord < n &&
                    colCord >= 0 && colCord < n &&
                    board[rowCord][colCord] == 'Q') {
                // short circuit evaluation
                return false;
            }
        }
    }

    return true;
}

bool nQueen(char board[][DIM], int n, int r) {
    // nQueen tell is possible?
    // if possible ...prints the board

    if (r >= n) {
        printBoard(board, n);
        cout << "=======================\n";
        return true;
    }

    for (int c = 0; c < n; ++c) {
        if (check(board, r, c, n) == true) {
            board[r][c] = 'Q';
            bool remBoard = nQueen(board, n, r + 1);
            // if (remBoard == true) {
                // return true;
                // continue;
            // } else {
                board[r][c] = 'X';
            // }
        }
    }
    return false;
}



int main() {
    char board[DIM][DIM] = {};

    int n;
    cin >> n;
    setBoard(board, n);

    bool ans = nQueen(board, n, 0);
    if (ans == true) {
        // printBoard(board, n);
        cout << "Printed\n";
    } else {
        cout << "Sorry Man! Can't place\n";
    }


}