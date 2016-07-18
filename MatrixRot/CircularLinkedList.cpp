#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

void CircularLinkedList::insert(int val) {
	if (tail == NULL) {
		head = new Node(val);
		tail = head;
		tail->next = head;
	} else {
		Node* newNode = new Node(val);
		newNode->next = head;
		tail->next = newNode;
		tail = newNode;
	}

	size = size + 1;
}

void CircularLinkedList::show() {
	Node* iter = head;
	do {
		std::cout << iter->val << std::endl;
		iter = iter->next;
	} while(iter != head);
}

void CircularLinkedList::rotate(int num_rots) {
	int eff_rots = num_rots % size;
	for (int j = 0; j < eff_rots; ++j) {
		head = head->next;
	}
}