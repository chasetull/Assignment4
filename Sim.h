//read in file
#pragma once
#include <iostream>
#include <fstream>
#include "Student.h"
#include "GenQueue.h"
using namespace std;

class Sim
{
	//read in test4.txt
	public:
		Sim();
		~Sim();

		void inReader(string path);

		void simulation();

		int winSize; //size of array of windows

		int sTick;


		string windows; //window count in
		int windCount; //actual count
		//int sCount; //student count wait

		int lineCount; //read in line count

		int tick; //clock tick time
		int clock;

		int queueTotal;

		string newStudents; //number of arriving students at tick STR
		string arriveTime; //clock tick

		string takeTime; //time each student needs at window ------- might remove

		

		ifstream opener;
		string temp;

		GenQueue<Student> sQueue;

};