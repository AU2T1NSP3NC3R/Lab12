#pragma once
#include <string>
#include <iostream>
class LinkedList
{
	public:
		struct node {
			node* next;
			std::string f_name;
			std::string l_name;
			int m_num;
		};

		node* head;
		int items;

		LinkedList();

		void insert(std::string, std::string, int);
		
		void print();


};

