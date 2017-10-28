#include "Board.h"
#include "Utility.h"
#include "Board_Coordinates.h"
#include "Piece_Factory.h"
#include "Piece.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Read and initialize board from a file
void Board::read(string filename)
{
	ifstream ifs;
	char input;
	ifs.open(filename);

	for (int row = 0; row < board_len_k; ++row)
		for (int col = 0; col < board_len_k; ++col)
			if (ifs >> input)
				board[row][col] = create_piece(input);

	ifs.close();
}

// Print out final solution to file 
void Board::write(string filename)
{
	ofstream ofs;
	ofs.open(filename);

	for (const auto& answer_list_coor : answer_list)
		ofs << answer_list_coor << '\n'; 

	ofs.close();
}

// Copy parameter board into private member variable board
void Board::copy_board(const std::shared_ptr<Piece> b[board_len_k][board_len_k])
{
	for (int row = 0; row < board_len_k; ++row)
		for (int col = 0; col < board_len_k; ++col)
			board[row][col] = b[row][col];
}

// Remove the pieec at the board coordinates to be empty.
void Board::remove_piece(const Board_Coordinates& bc)
{
	board[bc.row][bc.col] = create_piece('E');	
}

// Insert coordinates to answer_list
void Board::insert_coor_to_answer_list(const Board_Coordinates& bc)
{
	answer_list.push_back(bc);
}

// Helper function that is the main recursive call. Parameter coordinates details which piece
// that this board should remove, and at the same time, move to each possible location that the 
// piece can go to. 
void Board::solve_helper(const Board_Coordinates& bc)
{
	
}

// Main Solver Function
// Logic: Go through each piece to iterate through all possible combinations.
void Board::solve_kickstarter()
{
	for (int row = 0; row < board_len_k; ++row)
	{
		for (int col = 0; col < board_len_k; ++col)
		{
			// Check if piece is empty
			shared_ptr<Empty> empty_piece = dynamic_pointer_cast<Empty>(board[row][col]);
			if (!empty_piece) 
			{
				Board new_board;
				// vector<Board_Coordinates> v;
				Board_Coordinates bc{col, row};

				// Get vector of possible moves
				// v = board[row][col]->move(bc);
				
				// Copy board, remove the new piece, add to answer_list, and solve that board
				new_board.copy_board(board);
				// new_board.remove_piece(bc);
				new_board.solve_helper(bc);
				//new_board.solve();
			}
		}
	}
}