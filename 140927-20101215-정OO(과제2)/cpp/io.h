/*
	����:���α׷���(1~3)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
*/

#ifndef _IO_H_
#define _IO_H_

#include <iostream>

class IO{
public:
	std::string GetUserFile(int &V, int &E, int Option);

private:
	std::string FileRead(const char* fname, int& V, int& E);
	// '0' (��)
};

#endif