#include "list.h"

LinkedList::LinkedList() { head = nullptr, tail = nullptr; }

void LinkedList::printList()
{
	listNode* current = new listNode;
	current = head;
	int count = 1;
	while (current->next != nullptr) {
		cout << count << ".	" << current->name << endl;
		current = current->next;
		count++;
	}
	cout << count << ".	" << current->name << endl<<endl;
}

void LinkedList::insert(listNode* newData)
{
	//if list is empty then both the tail and head are the newData
	if (is_empty()) {
		head = newData;
		tail = newData;
		//cout << "head insert successful.";
	}
	else {
		/*Alt Tail Insert Code
		
		listNode* newNode = new listNode;
		newNode = newData;
		tail->next = newNode;
		tail = newNode;
		*/
		listNode* newNode = new listNode;
		newNode = newData;
		listNode* temp = head;
		
		//go to the end of the list aka the tail
		while (temp->next != nullptr) 
			temp = temp->next;
		temp->next = newNode;	//assign newNode to be the next value, after the last node in the list

		tail = newNode;		//newNode is the new tail bc it is now at the end of the list

		//cout << "end insert successful.";

	}
}

void LinkedList::remove(string targetCommand)
{
	listNode* current = new listNode;
	listNode* prev = new listNode;
	current = head;
	while (current->name != targetCommand && current->next != nullptr) {
		prev = current;
		current = current->next;
		
	}
	if (current->name == targetCommand) {
		prev->next = current->next;
		free(current);
		cout << "The command '" << targetCommand << "' has been removed from the list." << endl;
	}
	else
		cout << "This command is currently not in the list." << endl;
}

int LinkedList::is_empty(void)
{
	if (head == nullptr) {
		return 1;	//return 1 if list is empty
	}
	else return 0;	//return 0 if list is not empty
}

listNode* LinkedList::searchIndex(int index)
{
	if (index == 1) {
		return head;
	}
	else {
		listNode* current = new listNode;
		current = head;

		for (int i = 1; i < index ; i++) {
			current = current->next;
		}

		return current;
	}
}

int LinkedList::countItems()
{
	int count = 0;
	listNode* current = head;
	if (is_empty()) 
		return count;
	else {
		while (current->next != nullptr) {
			count++;
			current = current->next;
		}
		count++;
	}
	return count;
}

string LinkedList::randoDesc()
{
	listNode* current = head;
	int listLength = countItems(), randomDesc = rand() % listLength + 1;
	
	if (randomDesc == 1) {
		return head->description;
	}
	else {
		for (int i = 1; i <= randomDesc; i++) {
			current = current->next;
		}
		return current->description;
	}
}

listNode* LinkedList::randomCommandandDesc()
{
	listNode* current = head;
	int listLength = countItems(), randomCommand = rand() % listLength + 1;

	if (randomCommand == 1) {
		return head;
	}
	else {
		for (int i = 1; i <= randomCommand; i++) {
			current = current->next;
		}
		return current;
	}
}
