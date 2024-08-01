#include <iostream>

const char xPlayer = 'x';
const char oPlayer = 'o';
const char empty = ' ';

void printBoard(char board[3][3])
{
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
    std::cout << std::endl;
}

bool isEnd(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int z = 0; z < 3; z++)
        {
            if (board[i][z] == empty)
            {
                return false;
            }
        }
    }
    return true;
}

bool didWin(char player, char board[3][3])
{
    // check rows
  
  if(board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  }
  
  if(board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  
  if(board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  }
  
  // check columns
  
  if(board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  }
  
  if(board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    return true;
  }
  
  if(board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  }
  
  
  // check diagonal
  
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  
  if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  
  return false;
}

bool isLegalMove(int row, int col, char board[3][3])
{
    return row >= 0 && row <= 2 && col >= 0 && col <= 2 && board[row][col] == empty;
}

int main()
{
    // current player is either xPlayer or oPlayer
    char player = xPlayer; 

    // two dimensional array representing the tic tac toe board
    char board[3][3] = {
        {empty, empty, empty},
        {empty, empty, empty},
        {empty, empty, empty}};

    int row, col;
    while (true)
    {
        // get the move from the current player
        std::cout << player << ": please select the row: ";
        std::cin >> row;
        std::cout << player << ": please select the column: ";
        std::cin >> col;
        std::cout << std::endl;

        // if not legal, player lost
        if (isLegalMove(row, col, board) == false)
        {
            std::cout << "Player " << player << " lost due to illegal move :-(" << std::endl;
            break;
        }

        // apply the move to the board
        board[row][col] = player; 

        // draw the board in the console
        printBoard(board);

        // check if the current player won
        if (didWin(player, board))
        {
            std::cout << "Player " << player << " won!!!" << std::endl;
            break;
        }

        // check if the game is over (tie)
        if (isEnd(board))
        {
            std::cout << "Game over" << std::endl;
            break;
        }

        // select the next player (if current player is x, select o)
        if (player == xPlayer)
            player = oPlayer;
        else
            player = xPlayer;
    }
}