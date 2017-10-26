#include "Piece.h"
#include "Utility.h"
#include <vector>
#include <string>

using namespace std;

// Returns true if cooardinates are within 
inline bool Board_Coordinates::in_bounds()
{
	return (row >= 0 && row < board_len && col >= 0 && col < board_len);
}

// Number constructor that takes in parameter to determine the radius it can move.
Number::Number(string name)
{
	if (name == "One") {
		move_number = 1;
	}
	else if (name == "Two") {
		move_number = 2;
	}
	else if (name == "Three") {
		move_number = 3;
	}
	else if (name == "Four") {
		move_number = 4;
	}
	else {
		throw Error{"Trying to create an invalid Number piece!"};
	}
}

// Number pieces can move move_number in diagonal and straight lines
// radiating outwards from their curr_position.
vector<Board_Coordinates> Number::move(const Board_Coordinates& curr_position)
{
	vector<Board_Coordinates> v;

	for (int i = -1 * move_number; i <= move_number; ++move_number)
		for (int j = -1 * move_number; j <= move_number; ++move_number)
			if (i != 0 && j != 0)
			{
				int new_x = curr_position.x + i;
				int new_y = curr_position.y + j;

				v.push_back({curr_position.x + i, curr_position.y + j});
			}

	return v;
}

// Knight pieces move in "L" shapes from their starting position.
// Could do this logic in 2 for loops, but for sake of readability let's keep it like this.
vector<Board_Coordinates> Knight::move(const Board_Coordinates& curr_position)
{
	vector<Board_Coordinates> v;
	v.push_back(curr_position + 1, curr_position + 2);
	v.push_back(curr_position + 1, curr_position - 2);
	v.push_back(curr_position + 2, curr_position + 1);
	v.push_back(curr_position + 2, curr_position - 1);
	v.push_back(curr_position - 1, curr_position + 2);
	v.push_back(curr_position - 1, curr_position - 2);
	v.push_back(curr_position - 2, curr_position + 1);
	v.push_back(curr_position - 2, curr_position - 1);
	return v;
}

// Rook pieces move to the edges. 
vector<Board_Coordinates> Rook::move(const Board_Coordinates& curr_position)
{
	
}

vector<Board_Coordinates> Bishop::move(const Board_Coordinates& curr_position)
{
	
}

vector<Board_Coordinates> Queen::move(const Board_Coordinates& curr_position)
{
	
}