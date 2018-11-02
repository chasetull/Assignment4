/*
002297037
Chase Tullar
CPSC350
Assignment 4
10/26/19
*/

//doubly linked lists
#include <iostream>
#include "ListInterface.h"
#include "Student.h"
using namespace std;

template <class T> class ListNode
{
	public:
		ListNode();
		ListNode(T d);
		~ListNode();

		ListNode<T> *next;
		T data;
		ListNode<T> *prev;
};


template <class T> ListNode<T>::ListNode()
{
	//construct
}


template <class T> ListNode<T>::ListNode(T d)
{
	//overload
	data = d;
	next = NULL; //null pointer
	prev = nullptr; //same shit

}

template <class T> ListNode<T>::~ListNode()
{
	//destruct
	//research
}


//Double Link List class



//class reps a single linked list
template <class T> class DoubleLinkedList //: public ListInt  //has to extend ListInterface
{
	private:
		ListNode<T> *front;
		//DoubleLinkedList<T> *prev;
		//DoubleLinkedList<T> *next;
		//ListNode<T> *next;
		ListNode<T> *back;
		unsigned int size; //never negative int

	public:
		DoubleLinkedList();
		~DoubleLinkedList();
		void insertFront(T d);
		void insertBack(T d); //new
		T removeFront();
		T removeBack(); //new
		void printList();

		DoubleLinkedList<T> *remove(T key);

		int find(T val);
		unsigned int getSize();
		T deletePos(T pos);

		T getFront();
};

template <class T> DoubleLinkedList<T>::DoubleLinkedList()
{
	front = NULL;
	size = 0;
}

template <class T> DoubleLinkedList<T>::~DoubleLinkedList()
{
	//destroy somehow
}

template <class T> unsigned int DoubleLinkedList<T>::getSize()
{
	return size;
}

template <class T> void DoubleLinkedList<T>::printList()
{
	ListNode<T> *curr = front;

	while (curr) //while not NULL
	{
		cout << curr->data << endl;
		curr = curr->next; //change iterator curr to next node
	}
}

template <class T> void DoubleLinkedList<T>::insertFront(T d)
{
	ListNode<T> *node = new ListNode<T>(d); //ISSUE


	if (size == 0) //if list empty
	{
		back = node;
	}

	else
	{
		front->prev = node;
		node->next = front;
	}
	front = node;
	size++;
}

template <class T> void DoubleLinkedList<T>::insertBack(T d)
{
	ListNode<T> *node = new ListNode<T>(d);

	if (size == 0)
	{
		front = node;
	}

	else
	{
		back->next = node;
		node->prev = back;

	}
	back = node;
	size++;
}

template <class T> T DoubleLinkedList<T>::removeFront()
{
	ListNode<T> *temp = front;

	if (front->next == NULL) //if only node in list
	{
		back = NULL;
	}

	else
	{
		front->next->prev == NULL;
	}

	front = front->next; //change front to null node to be deleted
	temp->next = NULL; //remove
	T val = temp->data;

	delete temp;
	size--;

	return val;
}

template <class T> T DoubleLinkedList<T>::removeBack()
{
	//yay fun
}

template <class T> DoubleLinkedList<T>* DoubleLinkedList<T>::remove(T key) //might brake
{
	ListNode<T> *current = front;

	while (current->data != key)
	{
		current = current->next;
		if (current == NULL)
		{
			return NULL; //nothing to do if not found
		}
	}
	//if we get here we've found value to remove

	if (current == front)
	{
		front = current->next;
	}

	else //not front
	{
		current->prev = current->next;
	}

	if (current == back)
	{
		back = current->prev;
	}

	else
	{
		current->next->prev = current->prev;
	}

	current->next = NULL;
	current->prev = NULL;

	--size;

	return current;
}

template <class T> int DoubleLinkedList<T>::find(T val)
{
	int idx = -1;
	ListNode<T> *curr = front;

	while (curr != NULL) //begin searching
	{
		++idx;
		if(curr->data == val)
		{
			break;
		}

		else //did not find, cont search
		{
			curr = curr->next;
		}
	}

	if(curr == NULL)
	{
		idx = -1;
	}

	return idx;
}

template <class T> T DoubleLinkedList<T>::deletePos(T pos)
{
	int idx = 0;
	ListNode<T> *prev = front;
	ListNode<T> *curr = front;

	while (idx != pos)
	{
		prev = curr;
		curr = curr->next;
		++idx;
	}

	//when pos found

	//add logic to varify val was found
	prev->next = curr->next;
	curr->next = NULL;
	int d = curr->data;
	size--;

	delete curr;

	return d;
}

template <class T> T DoubleLinkedList<T>::getFront()
{
	return back->data; //FRONT
}