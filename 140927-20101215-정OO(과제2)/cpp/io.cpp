/*
	과제:프로그래밍(1~3)
	금오공과대학교(Kumoh National Institute of Technology)
	학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번: 20101215
	이름: 정원영
*/

#include <iostream>
#include <fstream>
#include <string>
#include "io.h"
#include "global.h"

using namespace std;

int CharToInt(const char d);

std::string IO::GetUserFile(int &V, int &E, int Option){

	std::string D;

	switch (Option)
	{
		case CMD_SEARCH:
			cout << "무방향 그래프가 저장된 파일명을 입력하시오(종료는 quit): ";
			break;

		case CMD_MINIMUM:
			cout << "무방향 가중치 그래프가 저장된 파일명을 입력하시오(종료는 quit): ";
			break;

		case CMD_TOPOLOGICAL:
			cout << "방향 그래프가 저장된 파일명을 입력하시오(종료는 quit): ";
			break;	
	}

	cin.sync();
	std::getline(cin, D);

	cout << endl;

	// 파일 내용 읽기(DISK TO MEMORY)
	D = FileRead(D.c_str(), V, E);

	return D;
}

std::string IO::FileRead(const char* fname, int& V, int &E){

	ifstream rtp(fname);
	std::string D;

	if (!rtp)
	{
		cout << "파일이 존재하지 않습니다." << endl;
		exit(1);
	}

	while (!rtp.eof() && rtp)
	{
		char* pstrBuffer = new char[MAX_SIZE];
		rtp.getline(pstrBuffer, MAX_SIZE);

		D.append(pstrBuffer);
		D.append("\n");

		if (V > 1)
			E++;

		V++;

	} // End of while

	V = CharToInt(D.at(FIRST));

	rtp.close();

	return D;
}
