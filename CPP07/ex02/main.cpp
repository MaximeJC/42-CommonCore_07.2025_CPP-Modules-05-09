#include "Array.hpp"

//? My main
int main() {
	Array<float> *emptyArray = new Array<float>();
	delete emptyArray;

	Array<int> intArray(5);

	for (size_t i = 0; i < intArray.size(); i++) {
		intArray[i] = i * 42;
	}
	std::cout << "-----=={Int Array}==-----" << std::endl;
	for (size_t i = 0; i < intArray.size(); i++) {
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	}

	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";
	std::cout << "-----=={String Array}==-----" << std::endl;
	for (size_t i = 0; i < stringArray.size(); i++) {
		std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
	}

	try {
		std::cout << intArray[10] << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}

//? main.cpp provided by the subject
//? Print 2 times "Index out of range"
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
// 			//? If this error is printed, there is a problem in code
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';	//! Print "Index out of range" here
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';	//! And print "Index out of range" here
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
