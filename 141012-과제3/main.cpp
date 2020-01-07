/*
	JLand(Sort) Project(과제:프로그래밍(7장 정렬 - 1인팀))
	OOOOOOOOOOO교
	소속 : 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번 : 20101215
	이름 : 정OO
	이메일 : rabbit.white@daum.net

	시작일 : 2014. 10. 8
	최종마감일 : 2014. 10. xx
*/

/* Multi Platform Support */
#ifdef WIN32
	#include <windows.h>
	#include <direct.h>
#else
	#include <unistd.h>
#endif

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include "global.h"
#include "j_model.h"

using namespace std;

void main()
{
	JLand JProgram;

	while (1)
	{
		int SELECT;
		Print(GLOBAL_PJT_SYSMAIN, GLOBAL_OPTION_TITLE); // 타이틀 올리기
		
		cin.clear();
		cin.sync();
		cin >> SELECT;

		if (SELECT == EXIT)
			break;

		switch (SELECT) // 메뉴
		{
			case MENU_INTEGER:								// 1번 - INTEGER 메뉴
				JProgram.Run(MENU_INTEGER);
				break;

			case MENU_DOUBLE:								// 2번 - DOUBLE 메뉴
				JProgram.Run(MENU_DOUBLE);
				break;

			case MENU_DOUBLE_POLYGON:						// 3번 - DOUBLE_POLYGON 메뉴
				JProgram.Run(MENU_DOUBLE_POLYGON);
				break;

			case MENU_STRING:								// 4번 - STRING 메뉴
				JProgram.Run(MENU_STRING);
				break;

			case MENU_ABOUT:								// 5번 - About 메뉴
				JProgram.About();
				break;
				
			default:									    // 미지원 메뉴
				Print(GLOBAL_PJT_SYSMAIN, GLOBAL_OPTION_MENU_NOT_FOUND);
				Cmd(CMD_DELAY, 1);
				Cmd(CMD_CLEAR);
				break;
		}

		Cmd(CMD_CLEAR);										// 초기화
		std::cout << endl;

	}

}

void Print(const int PJT_Name, const int Option){

	// Subject - PJT 분류
	switch (PJT_Name)
	{
		case GLOBAL_PJT_SYSMAIN:  // SysMain
			
			switch (Option)		   // OPTION
			{
				case GLOBAL_OPTION_TITLE:
					cout << "========================================================" << endl;
					cout << "	WELCOME JProject - Data Structrue" << endl;
					cout << "	By 정OO" << endl;
					cout << "	OOOOOOOOOOOOOOOOOOOOOOO교" << endl;
					cout << "	Business & Computer Science	Engineering" << endl;
					cout << "========================================================" << endl;
					cout << "(1번) integer" << endl;
					cout << "(2번) Double" << endl;
					cout << "(3번) Double(Polygon)" << endl;
					cout << "(4번) String" << endl;
					cout << "(5번) About" << endl;
					cout << "(0번) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "메뉴를 선택하세요: ";
					break;

				case GLOBAL_OPTION_WAIT:
					cout << "========================================================" << endl;
					cout << "잠시만 기다려주세요" << endl;
					cout << "========================================================" << endl;
					break;

				default:
					cout << "========================================================" << endl;
					cout << "지원하지 않는 메뉴" << endl;
					cout << "========================================================" << endl;
					break;

			} // end of switch

			break;	// end of SysMain

		case GLOBAL_PJT_JPROGRAM: // JProgram

			switch (Option)
			{
				case GLOBAL_OPTION_TITLE:
					cout << "========================================================" << endl;
					cout << "Welcome To JApp - Sort Wizard" << endl;
					cout << "Sort Wizard 마법사는 총 3단계(String만 제외)로 구성됩니다." << endl;
					cout << "========================================================" << endl;
					cout << "즐거운 하루 되십시요." << endl;
					cout << " & ** HAPPY BIRTH DAY ** &" << endl;
					cout << "========================================================" << endl;
					cout << "잠시만 읽어보시게요.";
					cout << endl;
					break;

				case GLOBAL_OPTION_TITLE_ANALYSIS:
					cout << "========================================================" << endl;
					cout << "Welcome To JApp - Sort Wizard - 1 / 3" << endl;
					cout << "분석 모드 선택 옵션" << endl;
					cout << "========================================================" << endl;
					cout << "(1번) 분석모드" << endl;
					cout << "(2번) 일반모드" << endl;
					cout << "(0번) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "메뉴를 선택하세요: ";
					break;

				case GLOBAL_OPTION_TITLE_RAND:
					cout << "========================================================" << endl;
					cout << "Welcome To JApp - Sort Wizard - 2 / 3" << endl;
					cout << "랜덤 유형의 형태를 선택하세요." << endl;
					cout << "========================================================" << endl;
					cout << "(1번) Rand_Low" << endl;
					cout << "(2번) Rand_Mid" << endl;
					cout << "(3번) Rand_High" << endl;
					cout << "(0번) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "메뉴를 선택하세요: ";
					break;

				case GLOBAL_OPTION_TITLE_USERSIZE:
					cout << "========================================================" << endl;
					cout << "Welcome To JApp - Sort Wizard - 3 / 3" << endl;
					cout << "크기 지정 : 사용자 크기를 입력하세요." << endl;
					cout << "========================================================" << endl;
					cout << "(사용자입력 : 정수 형태로 1 ~ (+n) 양수로)" << endl;
					cout << "(-1번) 랜덤형태(예측 불가)" << endl;
					cout << "(0번) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "메뉴를 선택하세요: ";
					break;

				case GLOBAL_OPTION_TITLE_POLYGON:
					cout << "========================================================" << endl;
					cout << "Welcome To JApp - Polygon" << endl;
					cout << "Criticia 지정";
					cout << "========================================================" << endl;
					cout << "(1번) X축 기준" << endl;
					cout << "(2번) Y축 기준" << endl;
					cout << "(3번) 넓이 기준" << endl;
					cout << "(0번) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "메뉴를 선택하세요: ";
					break;

				case GLOBAL_OPTION_MENU_NOT_FOUND:
					cout << "========================================================" << endl;
					cout << "지원하지 않는 메뉴" << endl;
					cout << "========================================================" << endl;
					break;

				default:
					break;

			} // end of switch

			break;  // end of JProgram

		case GLOBAL_PJT_JAPP:

			switch (Option)
			{
				case GLOBAL_OPTION_TITLE:

					cout << "========================================================" << endl;
					cout << "	Sort 기준" << endl;
					cout << "정렬할 서비스 번호를 입력하세요.";
					cout << "========================================================" << endl;
					cout << "(1번) BINARY_INSERT" << endl;
					cout << "(2번) LINK_INSERT(Polygon모드에선 미지원)" << endl;
					cout << "(3번) Recursive Quick Sort" << endl;
					cout << "(4번) Recursive Median of Three Quick Sort" << endl;
					cout << "(5번) Non-Recursive Median of Three Quick Sort" << endl;
					cout << "(6번) STD::SORT - Quick Sort" << endl;
					cout << "(7번) Recursive Merge Sort" << endl;
					cout << "(8번) Non-Recursive Merge Sort" << endl;
					cout << "(9번) Natural Merge Sort" << endl;
					cout << "(10번) Heap Sort" << endl;
					cout << "(11번) Bubble Sort" << endl;
					cout << "(12번) Selection Sort" << endl;
					cout << "(0번) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "메뉴를 선택하세요: ";

					break;

				default:
					cout << "========================================================" << endl;
					cout << "지원하지 않는 메뉴" << endl;
					cout << "========================================================" << endl;
					break;
			}

			break; // end of JApp

		case GLOBAL_PJT_POLYGON:  // Polygon

			switch (Option)		  // OPTION
			{
				case GLOBAL_OPTION_TITLE:
				
					cout << "========================================================" << endl;
					cout << "Build - 2014/10/10" << endl;
					cout << "With Rabbit.white(rabbit.white@daum.net)" << endl;
					cout << "Welcome To Polygon LAND" << endl;
					cout << "========================================================" << endl;
					break;

				case GLOBAL_OPTION_WAIT:
					cout << "========================================================" << endl;
					cout << "잠시만 기다려주세요" << endl;
					cout << "========================================================" << endl;
					break;

				case GLOBAL_OPTION_MENU_NOT_FOUND:
					cout << "========================================================" << endl;
					cout << "지원하지 않는 메뉴" << endl;
					cout << "========================================================" << endl;
					break;

				default:
					break;

			} // end of switch

			break; // End of Polygon

			

		default:
			break;
	}

}