/*
002297037
Chase Tullar
CPSC350
Assignment 4
10/26/19
*/

//GenQueue
#ifndef GENQUEUE_H
#define GENQUEUE_H
#include <iostream>
#include "DoubleLinkedList.h"
#include "Student.h"
using namespace std;

template <class T> class GenQueue //class .h
{
	public:
		GenQueue();
		//GenQueue(int maxsize);
		~GenQueue();
		void insert(T data);
		T remove();
		T peek();

		T isFull(); //bool?
		T isEmpty();
		int getSize();

	private:
		int front;
		int rear;
		int nullElement;
		int size;
		DoubleLinkedList<T> myQueue;
};

//generic implementation

template <class T> GenQueue<T>::GenQueue()
{
	//constructor
	nullElement = 0;
	front = 0;
	rear = -1;
}

/*
template <class T> GenQueue<T>::GenQueue(int maxsize)
{
	nullElement = 0;
	front = 0;
	rear = -1;
}
*/

template <class T> GenQueue<T>::~GenQueue()
{
	//destructor
	cout << "Queue destroyed" << endl;
}

template <class T> void GenQueue<T>::insert(T data)
{

	myQueue.insertFront(data);
	++nullElement;
}

template <class T> T GenQueue<T>::remove()
{
	myQueue.removeFront();
	cout << "window now occupied" << endl;
	--nullElement;

	/*
	T c = '\0'; //brake?
	c = myQueue[front];
	front++;

	//circular queue
	if(front == size)
	{
		front = 0;
	}

	nullElement--;
	return c;
	*/
}

template <class T> T GenQueue<T>::peek()
{
	return myQueue.getFront();
}

template <class T> T GenQueue<T>::isEmpty()
{
	return (nullElement == 0);
}



template <class T> int GenQueue<T>::getSize()
{
	return myQueue.getSize();
}

#endif