#include "LinkedList.h"


LinkedList::LinkedList() {
	head = nullptr;
	items = 0;
}

void LinkedList::insert(std::string fname, std::string lname, int mnum) {
	node* toAdd = new node;
	toAdd->f_name = fname;
	toAdd->l_name = lname;
	toAdd->m_num = mnum;
	toAdd->next = nullptr;

	if (items == 0) {	// adding to an empty list
		head = toAdd;
		items++;
		return;
	}
	
	node* temp = head;
	while (temp->next != nullptr) { // carries temp until it's next is a nullptr
		temp = temp->next;
	}

	temp->next = toAdd;
	items++;
	return;
	
}

void LinkedList::print() {
	if (items == 0) {	// trying to print an empty list
		std::cout << "The list is empty" << std::endl;
		return;
	}

	node* temp = head;

	while (temp->next != nullptr) {	// will print up until the last item
		std::cout << temp->f_name << ", " << temp->l_name << ": " << temp->m_num << std::endl;
		temp = temp->next;
		std::cout << "|" << std::endl;
		std::cout << "|" << std::endl;
	}
	std::cout << temp->f_name << ", " << temp->l_name << ": " << temp->m_num << std::endl;
	return;

}

