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

	// 분석 영역
	void CreateAnalysis(JTime* startTime, JTime* endTime, JUserVar* jvars);
	int GetWhereAnalysis();
	void SetWhereAnalysis(int sw);

	// 정렬 영역
	void SortOfRun(JUserVar* jvar, T* data, Node<T>* ndata = NULL);
	
	// 일반 생성
	LinkedList<T>* ListCreate(int valuetype, const int size);
	LinkedList<T>* ListCreate(T* data, const int size);

	T* Create(int valuetype, const int size);
	
	// Polygon 영역
	JPolygonList<T>* PolyCreateList(const int valuetype, const int size);
	T* PolyCreateView(JPolygonList<T>* data, const int critictype, const int size);
	
	void IndexToMerge(int* Arr, T* OriData, T* ChgData, const int n);	
	int* IndexCreate(const int size);

	// 출력 입력 영역(자동)
	void CreateAutomatric(JUserVar* jvar);

	// 출력 공통 영역
	int GetDataType(const int sorttype);
	void PrintCreate(Node<T>* data, T* Arr, const int printtype, JUserVar* jvar);
	void PrintCreate(JPolygonList<T>* data, int* Arr, const int printtype, JUserVar* jvar);
	std::string PrintTotalCreate(JUserVar* jvar);
	void PrintView(std::string printdata);
	std::string PrintAnalysis();

	// 파일 존재 파악
	int IsFileLoading();
	void ExtractFile(JUserVar* var);

private:
	// PrintInWriter(내부 관점으로 기록)
	void PrintInWriter(T* data, const int printtype, JUserVar* jvar);
	void PrintInWriter(T* data, const int* idxarr, const int printtype, JUserVar* jvar);
	void PrintInWriter(Node<T>* data, const int printtype, JUserVar* jvar);

	// 분석 도구 위치
	int PositionAnalysis;
};

#include "jAppController.h"
#include "jApp_PrintCreator.h"
#include "jApp_AnalysisTime.h"
#include "jApp_PolygonCreate.h"
#include "jApp_PrintInWriter.h"
#include "jApp_String.h"

#endif