#include <iostream>

#include "Node.h"

/**
 * Incomplete implementation of a circular singly linked list
 * for the purpose of this challenge.
 */

class CircularLinkedList
{
public:
	CircularLinkedList();
	void insert(int);
	void show();
	void rotate(int num_rots);

	int  size;
	Node* head;
	Node* tail;

};