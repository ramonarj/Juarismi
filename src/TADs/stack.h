#ifndef __STACK_RAQ__
#define __STACK_RAQ__
//Ram�n Arjona Qui�ones, 2024

#include "node.h"

template<typename T>
class Stack
{
public:
	/* Constructora */
	Stack() : count (0), last(nullptr) {}


	/* Inserta un elemento en la pila */
	void push(const T& elem);

	/* Saca el �ltimo elemento de la pila */
	void pop();

	/* Devuelve el �ltimo elemento de la pila, sin sacarlo */
	T top() const;

	/* Devuelve true si la pila no contiene ning�n elemento, false e.o.c. */
	inline bool empty() const { return count < 1; }

	inline unsigned int size() const { return count; }

private:
	/* N�mero de elementos en la pila */
	unsigned int count;
	/* Elemento en la cima de la pila */
	Node<T>* last;
};

// - - - - - - - - - - - - - - - 


template<typename T>
void Stack<T>::push(const T& elem)
{
	Node<T>* n = new Node<T>();
	// Pila vac�a
	if (count == 0)
	{
		n->sig = nullptr;
	}
	// Ya hab�a elementos
	else
	{
		n->sig = last;
	}
	n->elem = elem;
	last = n;

	count++;
}

template<typename T>
void Stack<T>::pop()
{
	Node<T>* aux = last;
	last = last->sig;
	delete aux;

	count--;
}

template<typename T>
T Stack<T>::top() const
{
	return last->elem;
}

#endif