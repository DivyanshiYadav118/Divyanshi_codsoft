#include <iostream>
using namespace std;

// Function to display the board
void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check for draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Function to switch players
char switchPlayer(char current) {
    return (current == 'X') ? 'O' : 'X';
}

// Function to reset the board
void resetBoard(char board[3][3]) {
    char pos = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = pos++;
}

int main() {
    char board[3][3];
    char currentPlayer;
    string choice;
    bool playAgain = true;

    do {
        resetBoard(board);
        currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            cout<<"*************WELCOME TO************ \n";
            cout<<"----------TIC-TAC-TOE GAME---------\n";
            displayBoard(board);
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9) {
                cout << "Invalid move! Enter a number from 1 to 9.\n";
                continue;
            }

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Cell already taken! Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            }
            else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                gameOver = true;
            }
            else {
                currentPlayer = switchPlayer(currentPlayer);
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        if (choice != "y" && choice != "Y")
            playAgain = false;

    } while (playAgain);

    cout << "Thank you for playing!\n";
    return 0;
}