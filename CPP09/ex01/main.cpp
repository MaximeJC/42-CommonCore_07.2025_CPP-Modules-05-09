#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
		return 1;
	}
	RPN rpn(argv[1]);
	rpn.execute();
	return 0;
}

// Int min :
// "0 9 9 + 1 + 7 * 5 * 2 * 1 + 2 * 1 + 2 * 2 * 5 * 1 + 5 * 2 * 2 * 2 * 2 * 2 * 2 * 1 + 2 * 3 * 3 * 7 * 1 + - 1 -"
// Int max :
// "9 9 + 1 + 7 * 5 * 2 * 1 + 2 * 1 + 2 * 2 * 5 * 1 + 5 * 2 * 2 * 2 * 2 * 2 * 2 * 1 + 2 * 3 * 3 * 7 * 1 +"
