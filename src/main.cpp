#include "TADs/stack.h"
#include <iostream>

void PruebaPila();

int main()
{
	PruebaPila();

	return 0;
}

void PruebaPila()
{
	Stack<int> s;
	s.push(3);
	s.push(5);
	s.push(-7);
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "\n" << s.size();
}