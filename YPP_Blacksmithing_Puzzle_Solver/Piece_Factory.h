#ifndef PIECE_FACTORY_H
#define PIECE_FACTORY_H

#include <string>
#include <memory>

// Incomplete declarations
class Piece;

/*  Factory function; Supply the information on the piece name and it creates
the specified kind of object and returns a pointer to it. */
std::shared_ptr<Piece> create_piece(const std::string& name);

#endif
