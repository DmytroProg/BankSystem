#pragma once
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class Logger
{
public:
	void LogInfo(string info) {
		ofstream ofs(path, ios_base::app);
		ofs << "<Info> [" << time(0) << "] " << info << endl;
		ofs.close();
	}

	void LogError(const exception& ex) {
		ofstream ofs(path, ios_base::app);
		ofs << "<Error> [" << time(0) << "] " << ex.what() << endl;
		ofs.close();
	}

private:
	string path = "log.txt";
};

