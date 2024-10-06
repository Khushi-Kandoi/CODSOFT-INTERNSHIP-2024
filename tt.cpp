// Before we start, let’s understand some rules to play the game:

// Rules of Tic-Tac-Toe
// Following are the rules that define how to play the tic tac toe game:

// A player can put only a single letter X or O in the 3 x 3 grid in each chance.
// Both players will get chances alternatively one after another till someone wins or draws. 
// To win this game, the player must create a horizontal, vertical, or diagonal line consisting of three same letters.
// The game is drawn, if all grids are filled with X or O letters but no line is made.
// Feature of Tic-Tac-Toe in C++
// This game provides the following features:

// This game is developed on a 3×3 grid.
// This game is designed for two players.
// Every player may choose a letter between X and O.
// Both players will get their chances to turn by turn.
// Components of the Game
// The game is made of the following components that include the functions and data structures to provide the basic operations of the game.

// 1. Game Board
// To create a tic-tac-toe board, a 3 x 3 array initialized with space is used.

// char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
// In this array, we will fill the X and O characters based on the moves of the players.

// 2. Movement Of Player
// Now we will create a function drawBoard() to display the Board. It will initialize the array and display the board after each move.

// The logic for user input and valid input checking is defined inside the main() function itself.

// How to check if the input is valid or not?

// Valid input: If the cell is empty and is within the boundary
// Invalid input: If the cell has already been filled with another letter or is outside the bounds.
// 3. Win, Lose or Draw
// The checkWin() function is used to check whether the player has won or not. The draw condition is checked in the main() function.

// C++ Program for Tic Tac Toe Game
// Below is the complete code for a basic console-based Tic-Tac-Toe game in C++:

// C++ program to implement tic tac toe game 
#include <iostream> 
using namespace std; 

// Function to draw the Tic-Tac-Toe board 
void drawBoard(char board[3][3]) 
{ 
	cout << "-------------\n"; 
	for (int i = 0; i < 3; i++) { 
		cout << "| "; 
		for (int j = 0; j < 3; j++) { 
			cout << board[i][j] << " | "; 
		} 
		cout << "\n-------------\n"; 
	} 
} 

// Function to check for a win 
bool checkWin(char board[3][3], char player) 
{ 
	// Check rows, columns, and diagonals 
	for (int i = 0; i < 3; i++) { 
		if (board[i][0] == player && board[i][1] == player 
			&& board[i][2] == player) 
			return true; 
		if (board[0][i] == player && board[1][i] == player 
			&& board[2][i] == player) 
			return true; 
	} 
	if (board[0][0] == player && board[1][1] == player 
		&& board[2][2] == player) 
		return true; 
	if (board[0][2] == player && board[1][1] == player 
		&& board[2][0] == player) 
		return true; 
	return false; 
} 

int main() 
{ 
	// Initialize the board and players 
	char board[3][3] = { { ' ', ' ', ' ' }, 
						{ ' ', ' ', ' ' }, 
						{ ' ', ' ', ' ' } }; 
	char player = 'X'; 
	int row, col; 
	int turn; // Declare turn here 

	cout << "Welcome to Tic-Tac-Toe!\n"; 

	// Game loop 
	for (turn = 0; turn < 9; turn++) { 
		// Draw the board 
		drawBoard(board); 

		// Prompt for valid input 
		while (true) { 
			cout << "Player " << player 
				<< ", enter row (0-2) and column (0-2): "; 
			cin >> row >> col; 

			if (board[row][col] != ' ' || row < 0 || row > 2 
				|| col < 0 || col > 2) { 
				cout << "Invalid move. Try again.\n"; 
			} 
			else { 
				break; // Valid input, exit the loop. 
			} 
		} 

		// Make the move 
		board[row][col] = player; 

		// Check for a win after making a move 
		if (checkWin(board, player)) { 
			drawBoard(board); 
			cout << "Player " << player << " wins!\n"; 
			break; // Exit the loop after a win. 
		} 

		// Switch to the other player 
		player = (player == 'X') ? 'O' : 'X'; 
	} 

	// End of the game 
	drawBoard(board); 

	// Check for a draw 
	if (turn == 9 && !checkWin(board, 'X') 
		&& !checkWin(board, 'O')) { 
		cout << "It's a draw!\n"; 
	}
	return 0; 
}
