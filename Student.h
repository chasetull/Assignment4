//students
#pragma once
#include <iostream>
using namespace std;

class Student
{
	public:
		Student();
		Student(string arriveTime, string takeTime);
		~Student();

		int wait; //how long student takes at window
		int sAmount; //student amount

		//string arriveTime;
		//string numStudents;
		int getWait();
		int getTime();
		//int getNumS();
		void setWait(int inWait);
		void setTime(int inTime);

};