#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>

/***** Board_Coordinates Class *****/
// Simple class to represent board Board_Coordinates.
// Row = 0 and Col = 0 represents top-left of board.
struct Board_Coordinates
{
	int x;
	int y;
	bool in_bounds(); // Determines if board_coordinates is within board bounds
};


/***** Piece Class *****/
// The Piece class is pure virtual with this header file containing all possible pieces
// needed for the scope of the YPP Blacksmithing Puzzle Solver program. Other pieces
// will inherit from this class in order to provide a simple overridden move() for the main driver.
class Piece
{
public:
	// Pure virtual move function; Override this to provide
	// implementation of what this Piece does when it is moved.
	// Returns a vector of all possible Board_Coordinates that is within board constraints.
	virtual std::vector<Board_Coordinates> move(const Board_Coordinates& curr_position) = 0;
};

/***** Empty Piece Class *****/
// This class represents the empty piece, meaning that this piece does not exist in the board.
class Empty : public Piece
{
public:
	// Returns empty vector
	virtual std::vector<Board_Coordinates> move(const Board_Coordinates& curr_position) override;
};

/***** Number Piece Class *****/
// This class represents the Pieces of `One`, `Two`, `Three`, and `Four` in the puzzle.
// The constructor determines the Piece's radius move range.
class Number : public Piece
{
public:
	// Constructor takes in paramter to determine the piece's number.
	// Called from Piece_Factory.h with the name given to factory
	Number(std::string name);

	// Moves depending on private move_number var
	virtual std::vector<Board_Coordinates> move(const Board_Coordinates& curr_position) override;

private:
	int move_number; // One, Two, Three, or Four
};


/***** Knight Piece Class *****/
// This class represents the `Knight` piece in the puzzle.
class Knight : public Piece
{
public:
	// Moves in "L" shapes along the board.
	virtual std::vector<Board_Coordinates> move(const Board_Coordinates& curr_position) override;
};

/***** Edge_Pieces Piece Class *****/
// This class represents pieces whose moves go to the edges.
class Edge_Pieces : public Piece 
{
public:
	std::vector<Board_Coordinates> horiz_vert_edge_move(const Board_Coordinates& curr_position);
	std::vector<Board_Coordinates> diagonal_edge_move(const Board_Coordinates& curr_position);
};

/***** Rook Piece Class *****/
// This class represents the `Rook` piece in the puzzle.
class Rook : public Edge_Pieces
{
public:
	// Moves in straight lines to the sides of the board.
	virtual std::vector<Board_Coordinates> move(const Board_Coordinates& curr_position) override;
};


/***** Bishop Piece Class *****/
// This class represents the `Bishop` piece in the puzzle.
class Bishop : public Edge_Pieces
{
public:
	// Moves in diagonal lines to the sides of the board.
	virtual std::vector<Board_Coordinates> move(const Board_Coordinates& curr_position) override;
};


/***** Queen Piece Class *****/
// This class represents the `Queen` piece in the puzzle.
// Inheriting from Rook and Bishop to use their own move() functions
class Queen : public Edge_Pieces
{
public:
	// Moves in diagonal and straight lines to the sides of the board.
	virtual std::vector<Board_Coordinates> move(const Board_Coordinates& curr_position) override;
};

#endif
