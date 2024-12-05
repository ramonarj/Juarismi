#ifndef __DEQUE_RAQ__
#define __DEQUE_RAQ__
// Ramón Arjona Quiñones, 2024

#include "node.h"

template<typename T>
class Deque
{
public:
	/* Constructora */
	Deque() : count(0), primer(nullptr), ultimo(nullptr) {}

	/* Introduce un elemento al principio de la cola doble */
	void push_front(const T& elem);
	/* Introduce un elemento al final de la cola doble */
	void push_back(const T& elem);

	/* Elimina el primer elemento de la cola doble */
	void pop_front();
	/* Elimina el últmo elemento de la cola doble */
	void pop_back();
	
	/* Devuelve el elemento al frente de la cola doble, sin sacarlo */
	T front() const;
	/* Devuelve el elemento al final de la cola doble, sin sacarlo */
	T back() const;

	/* Devuelve el número de elementos de la cola doble */
	inline unsigned int size() const { return count; }
	/* Devuelve true si la cola doble está  vacía, false e.o.c. */
	inline bool empty() const { return count < 1; }
private:
	/* Número de elementos de la cola doble */
	unsigned int count;
	/* Elemento en el frente de la cola */
	DoubleNode<T>* primer;
	/* Elemento al final de la cola */
	DoubleNode<T>* ultimo;
};

// - - - - - - - - - - - - - - - 

template<typename T>
void Deque<T>::push_front(const T& elem)
{
	DoubleNode<T>* n = new DoubleNode<T>();
	n->elem = elem;
	n->ant = nullptr;

	// Doble cola vacía
	if (count == 0)
	{
		n->sig = nullptr;
		ultimo = n;
	}
	// Ya había elementos
	else
	{
		n->sig = primer;
		primer->ant = n;
	}
	primer = n;

	count++;
}

template<typename T>
void Deque<T>::push_back(const T& elem)
{
	DoubleNode<T>* n = new DoubleNode<T>();
	n->elem = elem;
	n->sig = nullptr;
	// Doble cola vacía
	if(count == 0)
	{
		n->ant = nullptr;
		primer = n;
	}
	// Ya había elementos
	else
	{
		n->ant = ultimo;
		ultimo->sig = n;
	}
	ultimo = n;

	count++;
}

template<typename T>
void Deque<T>::pop_front()
{
	DoubleNode<T>* aux = primer;
	primer = primer->sig;

	// Si hay un segundo elemento, se actualiza
	if(primer != nullptr)
		primer->ant = nullptr;

	delete aux;
	count--;
}

template<typename T>
void Deque<T>::pop_back()
{
	DoubleNode<T>* aux = ultimo;
	ultimo = ultimo->ant;

	// Si hay un penúltimo elemento, se actualiza
	if(ultimo != nullptr)
		ultimo->sig = nullptr;

	delete aux;
	count--;
}

template<typename T>
T Deque<T>::front() const
{
	return primer->elem;
}

template<typename T>
T Deque<T>::back() const
{
	return ultimo->elem;
}

#endif