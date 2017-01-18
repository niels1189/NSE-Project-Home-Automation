#ifndef LOGFILE_H
#define LOGFILE_H
//#include <string>
class Log{
private:
	const char* loc;  //the name of the file to write in
public:
	void write(std::string text);   //write to given file
	void logInBed();		//write specific text | when going in bed
	void logOutBed();		//write specific text | when getting out of bed
	Log(const char* loc);		//constructor

};

#endif
