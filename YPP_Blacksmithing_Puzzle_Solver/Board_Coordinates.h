#ifndef BOARD_COORDINATES_H
#define BOARD_COORDINATES_H

#include <iostream>
#include "Utility.h"

/***** Board_Coordinates Class *****/
// Simple class to represent board Board_Coordinates.
// Row = 0 and Col = 0 represents top-left of board.
struct Board_Coordinates
{
	int col;
	int row;
	
	// Determines if board_coordinates is within board bounds
	bool in_bounds() { return (col >= 0 && col < board_len_k && row >= 0 && row < board_len_k); }
};

// Operator<< overload for Board_Coordinates
std::ostream& operator<<(std::ostream& os, const Board_Coordinates& bc);

#endif