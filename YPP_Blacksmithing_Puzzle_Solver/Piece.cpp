#include "Piece.h"
#include "Utility.h"
#include "Board_Coordinates.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Empty piece has no move
vector<Board_Coordinates> Empty::move(const Board_Coordinates& curr_position)
{
	return vector<Board_Coordinates>{};
}

// Number constructor that takes in parameter to determine the radius it can move.
Number::Number(char name)
{
	move_number = name - '0';
}

// Number pieces can move move_number in diagonal and straight lines
// radiating outwards from their curr_position.
vector<Board_Coordinates> Number::move(const Board_Coordinates& curr_position)
{
	vector<Board_Coordinates> v;

	for (int i = -1 * move_number; i <= move_number; i += move_number)
	{
		for (int j = -1 * move_number; j <= move_number; j += move_number)
		{
			if (i != 0 || j != 0) // Avoiding pushing the current position into vector
			{
				Board_Coordinates bc = {curr_position.col + i, curr_position.row + j};
				if (bc.in_bounds())
					v.push_back(bc);
			}
		}
	}

	return v;
}

// Knight pieces move in "L" shapes from their starting position.
// Could do this logic in 2 for loops, but for sake of readability let's keep it like this.
vector<Board_Coordinates> Knight::move(const Board_Coordinates& curr_position)
{
	vector<Board_Coordinates> v;
	Board_Coordinates bc;

	bc = {curr_position.col + 1, curr_position.row + 2};
	if (bc.in_bounds()) { v.push_back(bc); }
	
	bc = {curr_position.col + 1, curr_position.row - 2};
	if (bc.in_bounds()) { v.push_back(bc); }
	
	bc = {curr_position.col + 2, curr_position.row + 1};
	if (bc.in_bounds()) { v.push_back(bc); }
	
	bc = {curr_position.col + 2, curr_position.row - 1};
	if (bc.in_bounds()) { v.push_back(bc); }
	
	bc = {curr_position.col - 1, curr_position.row + 2};
	if (bc.in_bounds()) { v.push_back(bc); }
	
	bc = {curr_position.col - 1, curr_position.row - 2};
	if (bc.in_bounds()) { v.push_back(bc); }
	
	bc = {curr_position.col - 2, curr_position.row + 1};
	if (bc.in_bounds()) { v.push_back(bc); }
	
	bc = {curr_position.col - 2, curr_position.row - 1};
	if (bc.in_bounds()) { v.push_back(bc); }
	
	return v;
}

// Pieces move to the edges horizontally and vertically
std::vector<Board_Coordinates> Edge_Pieces::horiz_vert_edge_move(const Board_Coordinates& curr_position)
{
	vector<Board_Coordinates> v;

	if (curr_position.col != 0)
		v.push_back({0, curr_position.row});
	if (curr_position.row != 0)
		v.push_back({curr_position.col, 0});
	if (curr_position.col != board_len_k - 1)
		v.push_back({board_len_k - 1, curr_position.row});
	if (curr_position.row != board_len_k - 1)
		v.push_back({curr_position.col, board_len_k - 1});

	return v;
}

// Pieces move to the diagonal edges of the board
std::vector<Board_Coordinates> Edge_Pieces::diagonal_edge_move(const Board_Coordinates& curr_position)
{
	vector<Board_Coordinates> v;
	int delta = 0;
	int edge_of_board = board_len_k - 1; // To help calculate delta

	if (curr_position.col != 0 && curr_position.row != 0)
	{
		// Top Left
		delta = min(curr_position.col, curr_position.row);
		v.push_back({curr_position.col - delta, curr_position.row - delta});
	}

	if (curr_position.col != edge_of_board && curr_position.row != 0)
	{
		// Top Right
		delta = min(edge_of_board - curr_position.col, curr_position.row);
		v.push_back({curr_position.col + delta, curr_position.row - delta});
	}

	if (curr_position.col != 0 && curr_position.row != edge_of_board)
	{
		// Bottom Left
		delta = min(curr_position.col, edge_of_board - curr_position.row);
		v.push_back({curr_position.col - delta, curr_position.row + delta});
	}

	if (curr_position.col != edge_of_board && curr_position.row != edge_of_board)
	{
		// Bottom Right
		delta = edge_of_board - max(curr_position.col, curr_position.row);
		v.push_back({curr_position.col + delta, curr_position.row + delta});
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