#ifndef _TMANAGER_H_
#define _TMANAGER_H_

#include <iostream>
#include <string>
#include "jUserVariable.h"

const int MENU_INTEGER = 1;
const int MENU_DOUBLE = 2;
const int MENU_POLYGON = 3;
const int MENU_STRING = 4;
const int MENU_AUTO = 5;

const int MENU_SIZE_MIN = 1;
const int MENU_SIZE_MAX = 4;

class TaskManager{

public:
	TaskManager();
	~TaskManager();
	void MenuOfInteger(int* pArr, JUserVar* jvar = NULL);
	void MenuOfDouble(double* pArr, JUserVar* jvar = NULL);
	void MenuOfPolygon(int* pArr, JUserVar* jvar = NULL);
	void MenuOfString(std::string* pArr, JUserVar* jvar = NULL);
	void MenuOfAuto(JUserVar* jvar = NULL);

private:
};


#endif