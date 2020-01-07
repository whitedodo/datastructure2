#ifndef _J_USER_PARAMETER_H_
#define _J_USER_PARAMETER_H_

const int MANUAL = 1;
const int AUTO = 2;

#include <string>

class JUserVar{
public:
	JUserVar();
	~JUserVar();

	std::string GetPrintAnalysisStart();
	void SetPrintAnalysisStart(std::string _startAnalysis);

	std::string GetPrintAnalysisEnd();
	void SetPrintAnalysisEnd(std::string _endAnalysis);

	std::string GetPrintAnalysisEstimate();
	void SetPrintAnalysisEstimate(std::string _estimate);

	std::string GetPrintSortTitle();
	void SetPrintSortTitle(std::string _print_sort_title);

	std::string GetPrintOnTitle();
	void SetPrintOnTitle(std::string _print_on_title);

	std::string GetPrintOnMemo();
	void SetPrintOnMemo(std::string _print_on_memo);

	std::string GetPrintOffTitle();
	void SetPrintOffTitle(std::string _print_off_title);

	std::string GetPrintOffMemo();
	void SetPrintOffMemo(std::string _print_off_memo);

	std::string GetPrintMemo();
	void appendPrintMemo(std::string _print_memo);
	void SetPrintMemo(std::string _print_memo);

	int GetUserType();
	void SetUserType(int _usertype);
	
	int GetDataType();
	void SetDataType(int _datatype);

	int GetValueType();
	void SetValueType(int _valuetype);

	int GetUserSize();
	void SetUserSize(int _usersize);

	int GetSortType();
	void SetSortType(int _sorttype);

	int GetQuestion();
	void SetQuestion(int _question);

	int GetCriticType();
	void SetCriticType(int _critictype);

	void erase();

private:
	// 출력 영역
	std::string print_analysis_start;
	std::string print_analysis_end;
	std::string print_analysis_estimate;

	std::string print_sort_title;
	std::string print_on_title;
	std::string print_on_memo;
	std::string print_off_title;
	std::string print_off_memo;

	std::string print_memo;

	int usertype;
	int datatype;
	int valuetype, usersize, sorttype, question;
	int critictype;

};

#endif