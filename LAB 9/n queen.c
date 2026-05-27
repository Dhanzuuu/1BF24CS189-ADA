#include <stdio.h>

#define N 4

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col) {

    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;
    }

    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--) {

        if (board[i][j] == 1)
            return 0;
    }

    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N;
         i--, j++) {

        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

void solveNQueens(int board[N][N], int row) {

    if (row == N) {
        printBoard(board);
        return;
    }

    for (int col = 0; col < N; col++) {

        if (isSafe(board, row, col)) {

            board[row][col] = 1;

            solveNQueens(board, row + 1);

            board[row][col] = 0;
        }
    }
}

int main() {

    int board[N][N] = {0};

    solveNQueens(board, 0);

    return 0;
}
