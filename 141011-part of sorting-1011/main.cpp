/*
	과제:프로그래밍(7장 정렬 - 1인팀)
	OOOOOOOOOOOOOOOOOO교
	학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번: 20101215
	이름: 정OO
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "global.h"
#include "j_sort.h"

/* Multi Platform Support */
#ifdef WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif

using namespace std;

void Print(const int Subject, const int Option);

void main()
{
	JLand JProgram;

	while (1)
	{
		int SELECT;
		Print(GLOBAL_PJT_SYSMAIN, GLOBAL_OPTION_TITLE); // 타이틀 올리기
		
		cout << "메뉴를 선택하세요: ";
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
				
			default:									    // 미지원 메뉴
				Print(GLOBAL_PJT_SYSMAIN, GLOBAL_OPTION_MENU_NOT_FOUND);
				Cmd(CMD_DELAY, 1);
				Cmd(CMD_CLEAR);
				break;
		}

		Cmd(CMD_CLEAR);										// 초기화
		cout << endl;

	}

	//int bbc[5] = { 5, 7, 4, 6, 3 };
	//int bb[7] = { 5, 7, 4, 6, 3, 12, 19 };
	//int cc[7] = {NULL, 5, 7, 4, 6, 3, 12 };
	//int test[10] = { 26, 5, 77, 1, 61, 11, 59, 15, 48, 19 };

	//Sort<int> a;
	//LinkedList<int>* lst = new LinkedList<int>(SORT);
	//Polygon<int> zzz;
	//zzz.Run();

	//lst->Insert(31);
	//lst->Insert(25);
	//lst->Insert(12);
	//lst->Insert(40);
	//lst->Insert(13);
	//lst->Insert(22);
	//lst->Insert(2);								// Linked List Applied Insert Sort
	
	//a.BinaryInsertSort(bb, 6);						// BinaryInsert Sort

	//a.QuickSort(bb, 0, 6, TYPE_STD_QUICK);		// STD-QUICK
	//a.QuickSort(bb, 0, 6, TYPE_N_MEDIAN_QUICK);	// Non-Recur Median 3 Quick
	//a.QuickSort(bb, 0, 6, TYPE_R_MEDIAN_QUICK);	// Recur Median 3 Quick
	//a.QuickSort(bb, 0, 6, TYPE_R_QUICK);			// Recur Quick

	//a.MergeSort(bb, 0, 6, TYPE_R_MERGE);			// Recur Merge Sort
	//a.MergeSort(bb, 0, 6, TYPE_N_MERGE);			// Non-Recur Merge Sort
	//a.MergeSort(test, 0, 9, TYPE_NAT_MERGE);		// Natural Merge Sort

	//a.HeapSort(cc, 6);							// Heap Sort {eg: {NULL(이하 0), 5, 7, 4, 6, 3, 12 };}
	
	//a.BubbleSort(bb, 6);							// Bubble Sort
	//a.SelectionSort(bb, 6);						// Selection Sort

}

void Print(const int Subject, const int Option){

	// 주제 -> 세부주제
	switch (Subject)
	{
		case GLOBAL_PJT_SYSMAIN:  // JPROGRAM
			
			switch (Option)		   // OPTION
			{
				case GLOBAL_OPTION_TITLE:
					cout << "==============================================" << endl;
					cout << "WELCOME JProject - Data Structrue" << endl;
					cout << "	By 정OOO(OOO)" << endl;
					cout << "   OOO College" << endl;
					cout << "	Business & Computer Science" << endl;
					cout << "==============================================" << endl;
					cout << "1. integer" << endl;
					cout << "2. Double" << endl;
					cout << "3. Double(Polygon)" << endl;
					cout << "4. String" << endl;
					cout << "0. EXIT" << endl;
					cout << "==============================================" << endl;
					cout << endl;
					break;

				case GLOBAL_OPTION_WAIT:
					cout << "==============================================" << endl;
					cout << "잠시만 기다려주세요" << endl;
					cout << "==============================================" << endl;
					break;

				default:
					cout << "==============================================" << endl;
					cout << "지원하지 않는 메뉴" << endl;
					cout << "==============================================" << endl;
					break;

			} // end of switch
			
		break;	// end of JProgram

		case GLOBAL_PJT_POLYGON:  // Polygon

			switch (Option)		  // OPTION
			{
				case GLOBAL_OPTION_TITLE:
				
					cout << "==============================================" << endl;
					cout << "Build - 2014/10/10" << endl;
					cout << "With Rabbit.White(rabbit.white@daum.net)" << endl;
					cout << "Welcome To Polygon LAND" << endl;
					cout << "==============================================" << endl;
					break;

				case GLOBAL_OPTION_WAIT:
					cout << "==============================================" << endl;
					cout << "잠시만 기다려주세요" << endl;
					cout << "==============================================" << endl;
					break;

				default:

					cout << "==============================================" << endl;
					cout << "지원하지 않는 메뉴" << endl;
					cout << "==============================================" << endl;
					break;
			} // end of switch

			break; // End of Polygon

		default:
			break;
	}

}