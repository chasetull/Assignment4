//interface for DLL
//only funcs
#include <iostream>
using namespace std;

template <class T> class ListInt
{
	public:
		ListInt();
		~ListInt();
		void insertFront(T d);
		void insertBack(T d); //new
		T removeFront();
		T removeBack(); //new
		void printList();

		ListInt<T> *remove(T key); //changed ListInt from DoubleLinkedList

		int find(T val);
		unsigned int getSize();
		T deletePos(T pos);
};