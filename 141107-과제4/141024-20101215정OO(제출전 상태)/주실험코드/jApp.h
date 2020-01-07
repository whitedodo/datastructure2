#ifndef _JAPP_H_
#define _JAPP_H_

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "common.h"
#include "wizard.h"
#include "jUserVariable.h"
#include "ds.h"
#include "polygon.h"
#include "sort.h"

const int POLY_TYPE_X = 10;
const int POLY_TYPE_Y = 20;
const int POLY_TYPE_WEIGHT = 30;

const int TYPE_PRINT_ON = 50;
const int TYPE_PRINT_OFF = 60;

const int PRINT_NORMAL = 60;
const int PRINT_LINKED = 70;

const int ANALYSIS_INNER = 100;
const int ANALYSIS_OUTER = 200;

using namespace std;

template <typename T>
class JApp
{
public:
	JApp();
	~JApp();

	// �м� ����
	void CreateAnalysis(JTime* startTime, JTime* endTime, JUserVar* jvars);
	int GetWhereAnalysis();
	void SetWhereAnalysis(int sw);

	// ���� ����
	void SortOfRun(JUserVar* jvar, T* data, Node<T>* ndata = NULL);
	
	// �Ϲ� ����
	LinkedList<T>* ListCreate(int valuetype, const int size);
	LinkedList<T>* ListCreate(T* data, const int size);

	T* Create(int valuetype, const int size);
	
	// Polygon ����
	JPolygonList<T>* PolyCreateList(const int valuetype, const int size);
	T* PolyCreateView(JPolygonList<T>* data, const int critictype, const int size);
	
	void IndexToMerge(int* Arr, T* OriData, T* ChgData, const int n);	
	int* IndexCreate(const int size);

	// ��� �Է� ����(�ڵ�)
	void CreateAutomatric(JUserVar* jvar);

	// ��� ���� ����
	int GetDataType(const int sorttype);
	void PrintCreate(Node<T>* data, T* Arr, const int printtype, JUserVar* jvar);
	void PrintCreate(JPolygonList<T>* data, int* Arr, const int printtype, JUserVar* jvar);
	std::string PrintTotalCreate(JUserVar* jvar);
	void PrintView(std::string printdata);
	std::string PrintAnalysis();

	// ���� ���� �ľ�
	int IsFileLoading();
	void ExtractFile(JUserVar* var);

private:
	// PrintInWriter(���� �������� ���)
	void PrintInWriter(T* data, const int printtype, JUserVar* jvar);
	void PrintInWriter(T* data, const int* idxarr, const int printtype, JUserVar* jvar);
	void PrintInWriter(Node<T>* data, const int printtype, JUserVar* jvar);

	// �м� ���� ��ġ
	int PositionAnalysis;
};

#include "jAppController.h"
#include "jApp_PrintCreator.h"
#include "jApp_AnalysisTime.h"
#include "jApp_PolygonCreate.h"
#include "jApp_PrintInWriter.h"
#include "jApp_String.h"

#endif