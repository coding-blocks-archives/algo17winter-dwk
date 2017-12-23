// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cmath>
using namespace std;
const int DIM = 10;

void printBoard(int board[][DIM], int N){
    for(int r = 0; r < N; ++r){
        // cout << "+---+---+---+\n";
        cout << "+";
        for(int c = 0; c < N; ++c){
            if (c != 0 && c % 3 == 0) cout << "+";
            cout << board[r][c] << " ";
        }
        cout << "+" << endl;
    }
}


bool check(int board[][DIM], int r, int c, int N, int num){
    // check in row and col
    for(int i = 0; i < N; ++i){
        if (board[r][i] == num) return false;
        if (board[i][c] == num) return false;
    }

    int rootN = sqrt(N);
    int rowCord = r - r % rootN;
    int colCord = c - c % rootN;

    for(int i = rowCord; i < rowCord + rootN; ++i){
        for(int j = colCord; j < colCord + rootN; ++j){
            if (board[i][j] == num) return false;
        }
    }
    return true;
}


bool sudokuSolver(int board[][DIM], int r, int c, int N){
    if (r >= N){
        retn true;
    }

    if (c >= N){
        return sudokuSolver(board, r + 1, 0, N);
    }

    if (board[r][c] != 0){
        return sudokuSolver(board, r , c + 1, N);
    }

    for(int curNum = 1; curNum <= N; ++curNum){
        bool canPlace = check(board, r, c, N, curNum);
        if (canPlace == true){
            board[r][c] = curNum;
            bool remAns = sudokuSolver(board, r, c + 1, N);
            if (remAns == true){
                return true;
            }

            board[r][c] = 0;
        }
    }
    return false;

}

int main(){
    int N;  
    cin >> N;

    int board[DIM][DIM] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    bool ans = sudokuSolver(board, 0, 0, N);
    if (ans == true){
        printBoard(board, N);
    } else {
        cout << "I can't solve it. Even, you can't."  << endl;
    }

}