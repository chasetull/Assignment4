//window class
#include <iostream>
#include "Student.h"
using namespace std;

class Window
{
	public:
		bool isOpen;
		int isIdle;
		Student student;
		//Window *windTotal;

		Window();
		~Window();

		void setOpen();
		void setClose();

		void setStudent(Student s);

		bool isWinOpen();

};