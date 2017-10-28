#ifndef BOARD_H
#define BOARD_H

#include "Utility.h"
#include "Board_Coordinates.h"
#include <memory>
#include <string>
#include <list>

//////////////////////////////////////
//          PIECE LEGEND			//
//////////////////////////////////////
// Number 1: "1"					//
// Number 2: "2"					//
// Number 3: "3"					//
// Number 4: "4"					//
// Knight: "K"						//
// Rook: "R"						//
// Bishop: "B"						//
// Queen: "Q"						//
// Rum (not implemented yet): "X"	//
// Empty: "E"						//
//////////////////////////////////////

class Piece; // Incomplete declaration

class Board
{
public:
	// Read input and initialize board from filename
	void read(std::string filename);

	// Write output to filename
	void write(std::string filename);

	// Copie parameter 'b' board into this class's board
	void copy_board(const std::shared_ptr<Piece> b[board_len_k][board_len_k]);

	// Remove the pieec at the board coordinates to be empty.
	void remove_piece(const Board_Coordinates& bc);

	// Insert coordinates to answer_list
	void insert_coor_to_answer_list(const Board_Coordinates& bc);

	// Helper function that is the main recursive call. Parameter coordinates details which piece
	// that this board should remove, and at the same time, move to each possible location that the 
	// piece can go to. 
	void solve_helper(const Board_Coordinates& bc);

	// Kickstarter to solve algorithm, only used on RUM pieces or the 1st time the program begins
	// This solve function goes through the entire board piece-by-piece and creates a board
	// recursive instance to iterate through.
	void solve_kickstarter();

private:
	std::shared_ptr<Piece> board[board_len_k][board_len_k];
	std::list<Board_Coordinates> answer_list; // Contains results sequentially
};

#endif