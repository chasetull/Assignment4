//window .cpp
#include <iostream>
#include "Window.h"
using namespace std;

Window::Window()
{
	//constr
	isOpen = true; //window is open or closed
	isIdle = 0; //how long window waits for student
	student;

}

Window::~Window()
{
	//destr
}

void Window::setOpen()
{
	isOpen = true;
	cout << "window open" << endl;
}

void Window::setClose()
{
	isOpen = false;
	//cout << "window now occupied" << endl;
}

void Window::setStudent(Student s)
{
	student = s;
}

bool Window::isWinOpen() //check if window available
{
	return isOpen;
}