#include "Log.h"
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

Log::Log(const char* loc):loc(loc){}

void Log::Write(std::string text){
	ofstream File;
	File.open(loc, (std::ios_base::out|std::ios_base::app));
	File<<text;
	File.close();
}

void Log::LogInBed(){
	time_t t = time(0);   // get time now
	string y;
	y=ctime(&t);
	y.erase(y.find('\n'));
	Write(string(y + " : In Bed\n"));	
}

void Log::LogOutBed(){
	time_t t = time(0);   // get time now
	string y;
	y=ctime(&t);
	y.erase(y.find('\n'));
	Write(string(y + " : Out Bed\n"));	
}

