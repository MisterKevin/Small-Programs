#ifndef UTILITIES_H
#define UTILITIES_H

#include <exception>

/* Utility functions, constants, and globals needed for the program. */

// Global length of board
const int board_len_k = 6;

// Allowing program to throw errors.
class Error : public std::exception {
public:
	Error(const char* msg_) : msg(msg_) {}
    const char* what() const noexcept override
        {return msg;}
private:
	const char* msg;
};

#endif
