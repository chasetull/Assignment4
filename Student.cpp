//student .cpp
#include <iostream>
#include "Student.h"
using namespace std;

Student::Student()
{
	//constr
	//string arriveTime;
	//string numStudents;
}

Student::Student(string arriveTime, string takeTime)
{
	//copy
	wait = arriveTime[0] - '0';
	sAmount = takeTime[0] - '0';
}

Student::~Student()
{
	//destruct
}

int Student::getWait()
{
	return wait;
}

int Student::getTime()
{
	return sAmount;
}

void Student::setWait(int inWait)
{
	wait = inWait;
}

void Student::setTime(int inTime)
{
	sAmount = inTime;
}