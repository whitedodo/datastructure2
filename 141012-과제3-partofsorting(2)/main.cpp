/*
	JLand(Sort) Project(과제:프로그래밍(7장 정렬 - 1인팀))
	기관명 : OOOOOOOOOOOOOOO교
	소속 : 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번 : 20101215
	이름 : 정OO
	이메일 : rabbit.white@daum.net

*/


#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include "j_model.h"

using namespace std;

/*
	***************************************************
	View 영역
	---------------------------------------------------
*/

int main()
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

			case MENU_LINKED_INSERT:
				JProgram.Run(MENU_LINKED_INSERT);
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

	return 0;

}
