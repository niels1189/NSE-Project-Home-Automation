#ifndef LOGFILE_H
#define LOGFILE_H
#include <string>
class Log{
private:
	const char* loc;
public:
	void Write(std::string text);
	void LogInBed();
	void LogOutBed();
	Log(const char* loc);	

};

#endif