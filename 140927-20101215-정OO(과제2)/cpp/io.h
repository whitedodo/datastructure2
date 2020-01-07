/*
	과제:프로그래밍(1~3)
	금오공과대학교(Kumoh National Institute of Technology)
	학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번: 20101215
	이름: 정원영
*/

#ifndef _IO_H_
#define _IO_H_

#include <iostream>

class IO{
public:
	std::string GetUserFile(int &V, int &E, int Option);

private:
	std::string FileRead(const char* fname, int& V, int& E);
	// '0' (곰)
};

#endif