#include "Piece_Factory.h"
#include "Piece.h"
#include "Utility.h"
#include <memory>

using namespace std;

/*  Factory function; Supply the information on the piece name and it creates
the specified kind of object and returns a pointer to it. */
std::shared_ptr<Piece> create_piece(char name)
{
	if (name == '1' ||
		name == '2' ||
		name == '3' ||
		name == '4') {
		return make_shared<Number>(name);
	}
	if (name == 'K') {
		return make_shared<Knight>();
	}
	if (name == 'R') {
		return make_shared<Rook>();
	}
	if (name == 'B') {
		return make_shared<Bishop>();
	}
	if (name == 'Q') {
		return make_shared<Queen>();
	}
	if (name == 'E') {
		return make_shared<Empty>();
	}

	throw Error{"Trying to create an invalid Piece!"};
}