#include "Piece_Factory.h"
#include "Piece.h"
#include "Utility.h"
#include <memory>

using namespace std;

/*  Factory function; Supply the information on the piece name and it creates
the specified kind of object and returns a pointer to it. */
std::shared_ptr<Piece> create_piece(const std::string& name)
{
	if (name == "One" ||
		name == "Two" ||
		name == "Three" ||
		name == "Four") {
		return make_shared<Number>(name);
	}
	if (name == "Rook") {
		return make_shared<Rook>();
	}
	if (name == "Bishop") {
		return make_shared<Bishop>();
	}
	if (name == "Knight") {
		return make_shared<Knight>();
	}
	if (name == "Queen") {
		return make_shared<Queen>();
	}

	throw Error{"Trying to create an invalid Piece!"};
}