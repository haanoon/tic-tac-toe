#include <iostream>

using namespace std;

int main()
{
    char board[3][3];
    for(int j=0; j<3; j++)
    {
        for(int k=0; k<3; k++)
        {
            board[j][k] = '#';
        }
    }

    char player = 'X', winner = ' ';
    int row, column;
    bool completed = false;

    for(int i=0; i<9 && !completed; i++)
    {
        // Display the board
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<3; k++)
            {
                cout << board[j][k] << ' ';
            }
            cout << endl;
        }

        // Input move
        cout << "Player " << player << ", enter row number (0-2): ";
        cin >> row;
        cout << "Player " << player << ", enter column number (0-2): ";
        cin >> column;
        
        if(row < 0 || row >= 3 || column < 0 || column >= 3 || board[row][column] != '#')
        {
            cout << "Invalid move, try again." << endl;
            i--; // Decrement i to retry the move
            continue;
        }
        else
        {
            board[row][column] = player;
        }

        for(int j=0; j<3; j++)
        {
            if(board[j][0] == player && board[j][1] == player && board[j][2] == player)
            {
                winner = player;
                completed = true;
                break;
            }
            if(board[0][j] == player && board[1][j] == player && board[2][j] == player)
            {
                winner = player;
                completed = true;
                break;
            }
        }

        if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        {
            winner = player;
            completed = true;
        }
        if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        {
            winner = player;
            completed = true;
        }

        // Switch player
        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    // Display the final board
    for(int j=0; j<3; j++)
    {
        for(int k=0; k<3; k++)
        {
            cout << board[j][k] << ' ';
        }
        cout << endl;
    }

    // Output the result
    if(winner != ' ')
    {
        cout << "Player " << winner << " wins!" << endl;
    }
    else
    {
        cout << "The game is a draw!" << endl;
    }

    return 0;
}
