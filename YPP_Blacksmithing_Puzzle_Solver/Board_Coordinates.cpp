#include "Board_Coordinates.h"
#include <iostream>

using namespace std;

std::ostream& operator<<(std::ostream& os, const Board_Coordinates& bc)
{
	return os << '(' << bc.col << ',' << bc.row << ')';
}