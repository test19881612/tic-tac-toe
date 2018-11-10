/*
Author: Sameeraja Mamidipalli (Sam)
Purpose: Program to demonstarte classes and objects, and arrays by creating a Tic-Tac-Toe game. Determining Win/Cat's game
*/


#include <iostream>
#include <string>
using namespace std;

class Board {
	private:
//		const static string default_board[][3];												
		string board[3][3] = {{" 1 "," 2 "," 3 "},							
						{" 4 "," 5 "," 6 "},							
						{" 7 "," 8 "," 9 "}}; 
		
		string player_symbol = " ";	
		int input{};	
		string playerID = " ";
		int counter{};
		int row{}, col{};
		bool gameOver = false;	
		
	public:
		void displayBoard();		
//		void displayDefaultBoard();
		
		void setCounter(int);		
		void setPlayer();
		void setSymbol();
		void setInput(int value){
			input = value;
		}
		void setGameResult(bool result){
			gameOver = result;
		}

		bool makeMove();
		bool checkGameWon();
		bool checkRowsCols();
		bool checkDiagonal();		
		bool getGameResult(){
			return gameOver;
		}
		
		int getCounter() const{
			return counter;
		}
		string getPlayer(){
			return playerID;
		}
		
		string getSymbol(){
			return player_symbol;
		}					
} board1;

//const string Board::default_board[5][3] = {{" 1 |"," 2 |"," 3 "},
//						{"------------"},
//						{" 4 |"," 5 |"," 6 "},
//						{"------------"},
//						{" 7 |"," 8 |"," 9 "}};
						
void Board::displayBoard(){
	for (int num_rows = 0; num_rows < 3; num_rows++) // Row of the 2D array
	{
		for (int num_cols = 0; num_cols < 3; num_cols++) // Column of the 2D array
    	{
    		cout << board[num_rows][num_cols];
    		cout << " ";
		}
		cout << "\n\n";
	}
	cout << "\n";
}

//void Board::displayDefaultBoard(){
//	for (int num_rows = 0; num_rows < 5; num_rows++) // Row of the 2D array
//	{
//	    for (int num_cols = 0; num_cols < 3; num_cols++) // Column of the 2D array
//	    {
//	        cout << default_board[num_rows][num_cols];
//		}
//		cout << "\n";
//	}
//	cout << "\n";	
//	}
int get_input(int minValue, int maxValue) {	
	int num{};	
	while(true){	
		board1.setPlayer();		
		cout << "Player " << board1.getPlayer() << " please enter a number(1-9): ";
		if (cin >> num && num >= minValue && num <= maxValue) {
			return num;
		}
		else {
			cout << "Error: Invalid input" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');			
		}
	
	}
}

void Board::setCounter(int count){
	counter = count;
//	cout << "counter:" << counter << endl;
}	
void Board::setPlayer(){
	if (counter%2 == 0)
	playerID = "X";
	else
	playerID = "O";
//	cout << "player: " << playerID << endl;
}

void Board::setSymbol(){
	if (playerID == "X"){
	player_symbol = " X ";
	}
	else
	player_symbol = " O ";
//	cout << "symbol: " << player_symbol << endl;
}	

//function to convert input to row and column, then check if valid move and make move
bool Board::makeMove(){
	//cout << "in make move." << endl;
	int num_colums =  3;
	row = (input-1)/num_colums;
	col = ((input-1)%num_colums);
	//cout << "row: " << row << endl;
	//cout << "col: " << col << endl;
	//cout << "board[row][col]: " << board[row][col] << endl;
	 
	if (board[row][col] == " X " || board[row][col] == " O "){
		cout << "Sorry, you cannot make the same move again!" << endl;
		return false;						
	}
	else {
		setSymbol();
		getSymbol();
		board[row][col] = getSymbol();
		return true;
	}
}

//function to check if player won the game
bool Board::checkGameWon()
{
    if(input == 2 || input == 4 || input == 6 || input == 8)
    {
        return checkRowsCols();
    }
    else
    {
        return checkRowsCols() || checkDiagonal();
    }
}

//fucntion to check row and column wise first
bool Board::checkRowsCols(){	
//	cout <<"checking row" << endl;
	
	if (board[row][0] == board[row][1] &&
	board[row][1] == board[row][2])
	{
	   return true;
	}
	return false;
	
//	cout << "checking col" << endl;
	
	if(board[0][col] == board[1][col] &&
	board[1][col] == board[2][col])
	{
	    return true;
	}
	return false;
}
	
// function to check diagonals	
bool Board::checkDiagonal()
{    
	
//	cout << "Checking diagonals" << endl;
	
	if(board[0][0] == board[1][1] &&
	board[1][1] == board[2][2])
	{
	    return true;
	}
	return false;
	
	if(board[0][2] == board[1][1] &&
	board[1][1] == board[2][0])
	{
	    return true;
	}
	return false;
}
		
int main(){
	int count{};
	while (count<9 && !board1.getGameResult()){
		cout << "Please key in a number in the empty board following the positions \nin the below board to start playing Tic-Tac-Toe.\n" << endl;
//		board1.displayDefaultBoard();
		board1.displayBoard();

		int input = get_input(1,9);
		board1.setInput(input);
		bool result = board1.makeMove();
		//cout << "result" << result << endl;
		while(result==0){
			int input = get_input(1,9);
			//cout << "inside makeMove == False." << endl;
			board1.setInput(input);
			result = board1.makeMove();
		}	

		if (result == 1 && board1.checkGameWon()){
			cout << "Player " << board1.getPlayer() << " won!" <<  endl;
			board1.setGameResult(true);	
		}	
					
		++count;
		board1.setCounter(count);
		//cout << "counter in main: " << count << endl;
		if(!board1.getGameResult()){
			system("cls");
		}
				
	}
	cout << endl;
	board1.displayBoard();
	if (board1.getGameResult() == false && count>=9){
		cout << "No player won. It's a cat's game!" << endl;
	}
	return 0;
}

/*
Output:
1.showing Row-wise win:

Please key in a number in the empty board following the positions
in the below board to start playing Tic-Tac-Toe.

 X   X   3

 4   O   O

 7   8   9


Player X please enter a number(1-9): 3
Player X won!

 X   X   X

 4   O   O

 7   8   9



--------------------------------
Process exited after 30.37 seconds with return value 0
Press any key to continue . . .

2.showing diagonal win:

Please key in a number in the empty board following the positions
in the below board to start playing Tic-Tac-Toe.

 X   O   O

 4   X   6

 7   8   9


Player X please enter a number(1-9): 9
Player X won!

 X   O   O

 4   X   6

 7   8   X



--------------------------------
Process exited after 15.75 seconds with return value 0
Press any key to continue . . .

3.cat's game:


 X   X   O

 O   O   X

 X   O   X


No player won. It's a cat's game!

--------------------------------
Process exited after 26.17 seconds with return value 0
Press any key to continue . . .

*/
