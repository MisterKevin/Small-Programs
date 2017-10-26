#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include "Utility.h"
#include <iostream>
#include <memory>
#include <string>
#include <list>

class Board
{
public:
	// Read input and initialize board from filename
	void read(std::string filename);

	// Write output to filename
	void write(std::string filename);

	// Solve puzzle by finding optimal path to search for
	void solve();
private:
	std::shared_ptr<Piece> board[board_len_k][board_len_k];
	std::list<Board_Coordinates> answer_list;	// Contains results sequentially
};

#endif