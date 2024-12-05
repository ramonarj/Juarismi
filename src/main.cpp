#include "TADs/stack.h"
#include "TADs/queue.h"

#include <iostream>
#include <string>

void PruebaPila();
void PruebaCola();

int main()
{
	PruebaCola();

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

void PruebaCola()
{
	Queue<std::string> cola;
	cola.push("manzana");
	cola.push("naranja");
	cola.push("limon");
	while(!cola.empty())
	{
		std::cout << cola.front() << " ";
		cola.pop();
	}
	std::cout << "\n" << cola.size();
}