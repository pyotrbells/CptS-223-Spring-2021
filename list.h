#ifndef LIST_H
#define LIST_H

#include "PA1.h"
using namespace std;

struct listNode {
	string name;
	string description;
	int score;
	listNode* next;

};


class LinkedList {
	listNode* head;
	listNode* tail;
public:

	LinkedList();
	
	listNode* getHead() { return head; }
	void printList();
	void insert(listNode* newData);
	void remove(string targetCommand);
	int is_empty(void);

	listNode* searchIndex(int index);
	int countItems();
	string randoDesc();
	listNode* randomCommandandDesc();
};

#endif