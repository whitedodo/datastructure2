/*
	����:���α׷���(1~3)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
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
			cout << "������ �׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit): ";
			break;

		case CMD_MINIMUM:
			cout << "������ ����ġ �׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit): ";
			break;

		case CMD_TOPOLOGICAL:
			cout << "���� �׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit): ";
			break;	
	} // end of switch

	cin.sync();
	std::getline(cin, D);

	cout << endl;

	// ���� ���� �б�(DISK TO MEMORY)
	D = FileRead(D.c_str(), V, E);

	return D;
}

std::string IO::FileRead(const char* fname, int& V, int &E){

	ifstream rtp(fname);
	std::string D;

	if (!rtp)
	{
		cout << "������ �������� �ʽ��ϴ�." << endl;
		exit(1);
	} // end of if

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
