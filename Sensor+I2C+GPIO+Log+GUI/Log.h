#ifndef LOGFILE_H
#define LOGFILE_H
//#include <string>
class Log{
private:
	const char* loc;  //the name of the file to write in
public:
	void Write(std::string text);   //write to given file
	void LogInBed();		//write specific text | when going in bed
	void LogOutBed();		//write specific text | when getting out of bed
	Log(const char* loc);		//constructor

};

#endif
