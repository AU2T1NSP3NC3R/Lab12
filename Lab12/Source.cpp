#include "LinkedList.h"
#include <cstdlib>

int main() {
	LinkedList myList = LinkedList();

	std::string names[] = {"Joe", "Buck", "Todd", "Elizabeth", "Ricky", "Bobby", "Flynn", "Logan", "Dylan", "Igor"};

	for (int i = 0; i < 50; i++) {	// fills up myList with 50 randomly constructed students
		std::string fname = names[rand() % 10];
		std::string lname = names[rand() % 10];
		int mnum = rand() % 10000;

		myList.insert(fname, lname, mnum);
	}


	myList.print();

	int sort_dec = 0;
	int attr_dec = 0;
	int ascend_dec = 0;


	std::cout << "-----------------------------" << std::endl;
	std::cout << "| (1): Sort using bubble sort" << std::endl;
	std::cout << "| (2): Sort using insertion sort" << std::endl;
	std::cout << "| (3): Sort using radix sort" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Pick one of the choices above: ";
	std::cin >> sort_dec;
	std::cout << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << "| (1): Sort by first name " << std::endl;
	std::cout << "| (2): Sort by last name " << std::endl;
	std::cout << "| (3): Sort by m number" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Pick one of the choices above: ";
	std::cin >> attr_dec;
	std::cout << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << "| (1): Sort by ascending order " << std::endl;
	std::cout << "| (2): Sort by descending order " << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Pick one of the choices above: ";
	std::cin >> ascend_dec;


	return 0;
}