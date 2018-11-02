//g++ -o ass4 GenQueue.h DoubleLinkedList.h ass4Main.cpp ListInterface.h readIn.cpp Student.cpp Window.h

/*
002297037
Chase Tullar
CPSC350
Assignment 4
10/26/19
*/

//main for ass4
#include <iostream>
#include <fstream>
#include <sstream>
#include "GenQueue.h"
//#include "readIn.cpp"
#include "Sim.h"
using namespace std;

int main(int argc, char **argv)
{
	//main
	//ifstream openr;
	//string temp;
	//stringstream strToInt(temp);
	string path; //filePath

	int countr = 0; //line counter
	int studentAmnt; //we'll see

	Sim sims; //File reader instance

	cout << "filepath : (test4.txt)" << endl;
	cin >> path;

	if(path == "l")
	{
		path = "test4.txt";
	}

	while(path != "test4.txt")
	{
		cout << "Input Err" << endl;
		cin >> path;
	}

	sims.inReader(path); //read in file

	sims.simulation(); //perform sim
	

}