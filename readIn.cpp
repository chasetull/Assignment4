//read in file here
#include <iostream>
#include <fstream>
#include "Sim.h"
#include "Student.h"
#include "GenQueue.h"
//#include "Window.h"
#include "Window.cpp"
using namespace std;

Sim::Sim()
{
	//constr
	lineCount = 0;
	windows;
	windCount = 0;

	tick = 0;
	clock = -1;

	queueTotal = 0;
	winSize = 0;
	
	takeTime;
	//sdnt = 0;
	//sdnt2;
	//sdnt3;
	arriveTime;
	newStudents;
	//sCount = 0; //might delete
	sTick = 0;


}

Sim::~Sim()
{
	//destroy

}

void Sim::inReader(string path)
{
	opener.open(path);
	
	opener >> windows;

	windCount = windows[0] - '0'; //windows available
	cout << "Windows available: " << windCount << endl;



	//Window windows[windCount]; //array of windows

	if (opener.is_open())
	{
		while(opener >> arriveTime >> newStudents)
		{
			cout << stoi(newStudents) << " new students in queue" << endl;
			for(int i = 0; i < stoi(newStudents); i++)
			{
				//create new student
				opener >> takeTime;

				cout << "Student: " << arriveTime << "-tick, " << takeTime << "-sec" << endl;
				Student s1(arriveTime, takeTime); //ptr?

				int arriveTime1 = arriveTime[0] - '0';
				int takeTime1 = takeTime[0] - '0';

				s1.setWait(arriveTime1);
				s1.setTime(takeTime1);

				//add s to queue
				sQueue.insert(s1);
				++queueTotal; //increment size int

				Student peeks = sQueue.peek(); //hopeful instance of student
				sTick = peeks.getWait();

				//cout << "PEEK " << sTick << endl;
			}
			//cout << "hi" << endl;
		}

	}
	cout << "s arrive at " << sQueue.peek().getWait() << endl;
	Student sArray[queueTotal]; //array of students

}

void Sim::simulation() //simulation funct
{
	cout << "SIM START" << endl;

	Window windows[windCount]; //array of windows

	for(int j = 0; j < windCount; j++) //create instances of window
	{
		Window win; //new window
		windows[j] = win; //add window to array

		++winSize; //increment array size
	}

	while(queueTotal > 0) //while students in queue
	{
		++clock; //increment time

		cout << "(TIME : " << clock << ")" << endl;

		if(sQueue.peek().getWait() != clock) //if no student arrive at clock tick
		{
			cout << "No new students this tick" << endl;
			//continue;
		}
		//++clock; //increment time
		else if(sQueue.peek().getWait() == clock)
		{
			//cout << "at tick " << clock << ":" << endl;
			
			cout << "Student arrive time: " << sQueue.peek().getWait() << endl;
			
			for(int k = 0; k < winSize; k++) //BROKEN HERE IDK
			{

				if(windows[k].isWinOpen()) //if window avail
				{
					windows[k].setStudent(sQueue.peek()); //put queue stud in open window
					cout << "Student needs " << sQueue.peek().getTime() << " secs at window" << endl;

					sQueue.remove(); //remove student from queue

					//.remove() doesn't remove student from queue. brakes everything




					windows[k].setClose(); //dont show window as open
					--queueTotal; //remove student from line

					
					//cout << "student went to window" << endl;

					//cout << "Student needs " << sQueue.peek().getTime() << " secs at window" << endl;

					cout << queueTotal << " students left in queue" << endl;

					k = winSize; //remove when DELETE works

					
					if(sQueue.peek().getWait() == clock && sQueue.peek().getTime() == 10)
					{
						windows[k].setStudent(sQueue.peek()); //put queue stud in open window

						sQueue.remove(); //remove student from queue

						windows[k].setClose(); //dont show window as open
						--queueTotal; //remove student from line

						
						//cout << "student went to window" << endl;

						cout << "Student needs " << sQueue.peek().getTime() << " secs at window" << endl;

						cout << queueTotal << " students left in queue" << endl;

						k = winSize;
					}

					//k = winSize;

					// if(queueTotal == 2)
					// {
					// 	--clock;
					// }

					//sQueue.getSize();

					//continue;

					
				}
			}
			
		}

		if(clock > 4)
		{
			cout << "Terminated - loop" << endl; //fmylife
			exit(0);

		}


		//++clock; //increment time

		
	}
}