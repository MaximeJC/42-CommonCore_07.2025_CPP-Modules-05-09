#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <stack>

int main() {

	//! Uncommenting this code will result in a compilation error
	//! because std::stack does not support iterators.

	// std::cout << "-----=={Base Stack}==-----" << std::endl;
	// std::stack<int> stack;
	// stack.push(1);
	// stack.push(2);
	// std::cout << "Elements in Base Stack:" << std::endl;
	// std::stack<int>::iterator stackIt = stack.begin();		//* This line will cause a compilation error
	// std::stack<int>::iterator stackIte = stack.end();		//* This line will cause a compilation error
	// ++stackIt;
	// --stackIte;
	// while (stackIt != stackIte)
	// {
	// 	std::cout << *stackIt << " ";
	// 	++stackIt;
	// }
	// std::cout << std::endl;

	std::cout << "-----=={MutantStack (Subject) Tests}==-----" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Elements in MutantStack:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--ite;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);	// Copy to standard stack

	std::cout << "-----=={List Tests}==-----" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Last element: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size after pop: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "Elements in classic list:" << std::endl;
	std::list<int>::iterator lstIt = lst.begin();
	std::list<int>::iterator lstIte = lst.end();
	++lstIt;
	--lstIte;
	while (lstIt != lstIte)
	{
		std::cout << *lstIt << " ";
		++lstIt;
	}
	std::cout << std::endl;

	return 0;
}
