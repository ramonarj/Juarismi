#include "TADs/stack.h"
#include "TADs/queue.h"
#include "TADs/deque.h"

#include "Algoritmos/NReinas.h"

#include <iostream>
#include <string>

void PruebaPila();
void PruebaCola();
void PruebaDobleCola();

void PruebaNReinas();

int main()
{
	PruebaNReinas();

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

void PruebaDobleCola()
{
	Deque<float> deque;
	deque.push_front(1.5);
	deque.push_back(9);
	deque.push_front(-0.01);
	deque.push_back(100);
	while(!deque.empty())
	{
		std::cout << deque.front() << " ";
		deque.pop_front();

		if (deque.empty())
			return;

		std::cout << deque.back() << " ";
		deque.pop_back();
	}
	std::cout << "\n" << deque.size();
}

void PruebaNReinas()
{
	long t = clock();

	NReinas nreinas(8, 8);
	nreinas.resuelve();

	if (nreinas.numSoluciones != 0)
		std::cout << "Hay " << nreinas.numSoluciones << " soluciones posibles" << std::endl;
	else
		std::cout << "No hay solución" << std::endl;

	t = clock() - t;
	std::cout << "Tiempo empleado: " << t / 1000.0 << " segundos" << std::endl;
}