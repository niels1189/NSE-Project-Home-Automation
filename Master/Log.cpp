#include "Log.h"
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

Log::Log(const char* loc):loc(loc){} //the constructor saving the given file name

void Log::write(std::string text){ //write the text on the given file
	ofstream File;
	File.open(loc, (std::ios_base::out|std::ios_base::app)); //open file (containing content)
	File<<text;  //write text to file
	File.close();  //close file (save file)
}

void Log::logInBed(){
	time_t t = time(0);   // get epoch now
	string y;	
	y=ctime(&t);		//convert epoch into date string
	y.erase(y.find('\n'));  //remove the end of the string
	write(string(y + " : In Bed\n"));	//add the text ": in bed" and write to log files
}

void Log::logOutBed(){
	time_t t = time(0);   // get epoch now
	string y;
	y=ctime(&t);		//convert epoch to date string
	y.erase(y.find('\n'));  //remove the end of the string
	write(string(y + " : Out Bed\n"));	//add the text ": out bed" and write to log file
}

