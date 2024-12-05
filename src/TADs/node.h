#ifndef __NODE_RAQ__
#define __NODE_RAQ__

template<typename T>
struct Node
{
	T elem;
	Node* sig;
};

// - - - - - - - - - - - - -

template<typename T>
struct DoubleNode
{
	T elem;
	DoubleNode* ant;
	DoubleNode* sig;
};

#endif