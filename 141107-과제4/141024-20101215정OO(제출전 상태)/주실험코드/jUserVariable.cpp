#include <iostream>
#include <string>
#include "jUserVariable.h"

using namespace std;

JUserVar::JUserVar(){

}

JUserVar::~JUserVar(){

}

std::string JUserVar::GetPrintAnalysisStart(){
	return print_analysis_start;
}

void JUserVar::SetPrintAnalysisStart(std::string _startAnalysis){
	print_analysis_start = _startAnalysis;
}

std::string JUserVar::GetPrintAnalysisEnd(){
	return print_analysis_end;
}

void JUserVar::SetPrintAnalysisEnd(std::string _endAnalysis){
	print_analysis_end = _endAnalysis;
}

std::string JUserVar::GetPrintAnalysisEstimate(){
	return print_analysis_estimate;
}

void JUserVar::SetPrintAnalysisEstimate(std::string _estimate){
	print_analysis_estimate = _estimate;
}

std::string JUserVar::GetPrintSortTitle(){
	return print_sort_title;
}

void JUserVar::SetPrintSortTitle(std::string _print_sort_title){
	print_sort_title = _print_sort_title;
}

std::string JUserVar::GetPrintOnTitle(){
	return print_on_title;
}

void JUserVar::SetPrintOnTitle(std::string _print_on_title){
	print_on_title = _print_on_title;
}

std::string JUserVar::GetPrintOnMemo(){
	return print_on_memo;
}

void JUserVar::SetPrintOnMemo(std::string _print_on_memo){
	print_on_memo = _print_on_memo;
}

std::string JUserVar::GetPrintOffTitle(){
	return print_off_title;
}

void JUserVar::SetPrintOffTitle(std::string _print_off_title){
	print_off_title = _print_off_title;
}

std::string JUserVar::GetPrintOffMemo(){
	return print_off_memo;
}

void JUserVar::SetPrintOffMemo(std::string _print_off_memo){
	print_off_memo = _print_off_memo;
}

int JUserVar::GetUserType(){
	return usertype;
}

void JUserVar::SetUserType(int _usertype){
	usertype = _usertype;
}

int JUserVar::GetDataType(){
	return datatype;
}

void JUserVar::SetDataType(int _datatype){
	datatype = _datatype;
}

int JUserVar::GetValueType(){
	return valuetype;
}

void JUserVar::SetValueType(int _valuetype){
	valuetype = _valuetype;
}

int JUserVar::GetUserSize(){
	return usersize;
}

void JUserVar::SetUserSize(int _usersize){
	usersize = _usersize;
}

int JUserVar::GetQuestion(){
	return question;
}

void JUserVar::SetQuestion(int _question){
	question = _question;
}

int JUserVar::GetSortType(){
	return sorttype;
}

void JUserVar::SetSortType(int _sorttype){
	sorttype = _sorttype;
}

std::string JUserVar::GetPrintMemo(){
	return print_memo;
}

void JUserVar::appendPrintMemo(std::string _print_memo){
	print_memo.append(_print_memo);
}

void JUserVar::SetPrintMemo(std::string _print_memo){
	print_memo = _print_memo;
}

int JUserVar::GetCriticType(){
	return critictype;
}

void JUserVar::SetCriticType(int _critictype){
	critictype = _critictype;
}

void JUserVar::erase()
{

	print_analysis_start.erase();
	print_analysis_end.erase();
	print_analysis_estimate.erase();

	print_sort_title.erase();
	print_on_title.erase();
	print_on_memo.erase();
	print_off_title.erase();
	print_off_memo.erase();

	print_memo.erase();

	usertype = 0;
	valuetype = 0;
	usersize = 0;
	sorttype = 0;
	question = 0;

}