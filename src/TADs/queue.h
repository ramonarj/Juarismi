#ifndef __QUEUE_RAQ__
#define __QUEUE_RAQ__
// Ram�n Arjona Qui�ones, 2024

#include "node.h"

template<typename T>
class Queue
{
public:
	/* Constructora */
	Queue() : count(0), primer(nullptr), ultimo(nullptr) {}

	/* Introduce un elemento al fondo de la cola */
	void push(const T& elem);

	/* Devuelve el elemento al frente de la cola, sin sacarlo */
	T front() const;

	/* Saca el elemento del frente de la cola */
	void pop();

	/* Devuelve true si la cola est� vac�a, false e.o.c. */
	inline bool empty() const { return count < 1; }

	/* Devuelve el n�mero de elementos de la cola */
	inline unsigned int size() const { return count; }
private:
	/* N�mero de elementos */
	unsigned int count;
	/* El elemento que saldr� el siguiente de la cola */
	Node<T>* primer;
	/* El �ltimo elemento que se ha introducido en la cola */
	Node<T>* ultimo;
};

// - - - - - - - - - - - - - - - - - - - - 

template<typename T>
void Queue<T>::push(const T& elem)
{
	Node<T>* n = new Node<T>();
	n->elem = elem;
	n->sig = nullptr;

	// Cola vac�a
	if(count == 0)
	{
		primer = n;
	}
	// Ya hab�a elementos
	else
	{
		ultimo->sig = n;
	}
	ultimo = n;

	count++;
}

template<typename T>
void Queue<T>::pop()
{
	Node<T>* aux = primer;
	primer = primer->sig;
	delete aux;

	count--;
}

template<typename T>
T Queue<T>::front() const
{
	return primer->elem;
}

#endif