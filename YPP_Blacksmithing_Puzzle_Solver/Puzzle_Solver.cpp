#include "Board.h"
#include <iostream>

using namespace std;

int main()
{
	Board b;

	try
	{
		b.read("puzzle_solver_input.txt");
		b.solve();
		b.write("puzzle_solver_output.txt");
	}
	catch (Error& e)
	{
		cout << e.what() << endl;
	}
	
	return 0;
}