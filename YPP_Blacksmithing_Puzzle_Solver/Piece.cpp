#include "Piece.h"
#include "Utility.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Returns true if cooardinates are within 
inline bool Board_Coordinates::in_bounds()
{
	return (x >= 0 && x < board_len_k && y >= 0 && y < board_len_k);
}

// Empty piece has no move
vector<Board_Coordinates> Empty::move(const Board_Coordinates& curr_position)
{
	return vector<Board_Coordinates>{};
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
				v.push_back({curr_position.x + i, curr_position.y + j});

	return v;
}

// Knight pieces move in "L" shapes from their starting position.
// Could do this logic in 2 for loops, but for sake of readability let's keep it like this.
vector<Board_Coordinates> Knight::move(const Board_Coordinates& curr_position)
{
	vector<Board_Coordinates> v;
	v.push_back({curr_position.x + 1, curr_position.y + 2});
	v.push_back({curr_position.x + 1, curr_position.y - 2});
	v.push_back({curr_position.x + 2, curr_position.y + 1});
	v.push_back({curr_position.x + 2, curr_position.y - 1});
	v.push_back({curr_position.x - 1, curr_position.y + 2});
	v.push_back({curr_position.x - 1, curr_position.y - 2});
	v.push_back({curr_position.x - 2, curr_position.y + 1});
	v.push_back({curr_position.x - 2, curr_position.y - 1});
	return v;
}

// Pieces move to the edges horizontally and vertically
std::vector<Board_Coordinates> Edge_Pieces::horiz_vert_edge_move(const Board_Coordinates& curr_position)
{
	vector<Board_Coordinates> v;

	if (curr_position.x != 0)
		v.push_back({0, curr_position.y});
	if (curr_position.y != 0)
		v.push_back({curr_position.x, 0});
	if (curr_position.x != board_len_k - 1)
		v.push_back({board_len_k - 1, curr_position.y});
	if (curr_position.y != board_len_k - 1)
		v.push_back({curr_position.x, board_len_k - 1});

	return v;
}

// Pieces move to the diagonal edges of the board
std::vector<Board_Coordinates> Edge_Pieces::diagonal_edge_move(const Board_Coordinates& curr_position)
{
	vector<Board_Coordinates> v;
	int delta = 0;

	if (curr_position.x != 0 && curr_position.y != 0)
	{
		// Bottom Left
		delta = min(curr_position.x, curr_position.y);
		v.push_back({curr_position.x - delta, curr_position.y - delta});
	}

	if (curr_position.x != board_len_k - 1 && curr_position.y != 0)
	{
		// Bottom Right
		delta = min(board_len_k - curr_position.x, curr_position.y);
		v.push_back({curr_position.x + delta, curr_position.y - delta});
	}

	if (curr_position.x != 0 && curr_position.y != board_len_k - 1)
	{
		// Top Left
		delta = min(curr_position.x, board_len_k - curr_position.y);
		v.push_back({curr_position.x - delta, curr_position.y + delta});
	}

	if (curr_position.x != board_len_k - 1 && curr_position.y != board_len_k - 1)
	{
		// Top Right
		delta = board_len_k - max(curr_position.x, curr_position.y);
		v.push_back({curr_position.x + delta, curr_position.y + delta});
	}

	return v;
}

// Rook pieces move to the edges. 
vector<Board_Coordinates> Rook::move(const Board_Coordinates& curr_position)
{
	return horiz_vert_edge_move(curr_position);
}

// Bishop pieces move to diagonal edges
vector<Board_Coordinates> Bishop::move(const Board_Coordinates& curr_position)
{
	return diagonal_edge_move(curr_position);
}

// Queen pieces move to both Bishop edges and Rook edges, so merge the two
vector<Board_Coordinates> Queen::move(const Board_Coordinates& curr_position)
{
	vector<Board_Coordinates> v = horiz_vert_edge_move(curr_position);
	vector<Board_Coordinates> v_diagonal = diagonal_edge_move(curr_position);
	v.insert(v.end(), v_diagonal.begin(), v_diagonal.end());
	return v;
}