#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <time.h>

const int TRUE = 1;
const int FALSE = 0;

const int MENU_MANUAL = 1;
const int MENU_AUTO = 2;
const int MENU_EXIT = 0;

using namespace std;

void MenuOfManual(int* ptr);
void MenuOfAuto(int* ptr);

int main()
{
	int CHOOSE;
	int *ptr = NULL;

	while (1)
	{
		cout << "OOOOOOOOOOOOOOOOOOO교" << endl;
		cout << "Dept. Business and Computer Software Engineering" << endl;
		cout << "C++ std::sort" << endl;
		cout << "정OO(OOOOOOOOOOOOOO Jeong)" << endl;
		cout << "1번 수동조작" << endl;
		cout << "2번 자동조작" << endl;
		cout << "0번 탈출" << endl;
		cout << "메뉴를 선택하세요 : ";

		cin.clear();
		cin.sync();
		cin >> CHOOSE;

		if (CHOOSE == MENU_EXIT)
			break;

		switch (CHOOSE)
		{
		case MENU_MANUAL:
			MenuOfManual(ptr);
			break;

		case MENU_AUTO:
			MenuOfAuto(ptr);
			break;

		default:
			break;
		}

	}

}

void MenuOfManual(int* ptr){

	int i;
	int arr_size;
	int CHOOSE = 0;
	float start, stop;

	while (1)
	{
		cout << "숫자를 입력하세요 : ";
		cin >> CHOOSE;

		if (CHOOSE <= 0)
			cout << "음수 미지원" << endl;
		else
			break;

	} // end of while

	ptr = new int[CHOOSE];

	// 랜덤 활성화
	srand(time(NULL));

	i = 0;

	// 정렬 전
	cout << "정렬 전: ";

	while (i < CHOOSE)
	{
		ptr[i] = ((rand() % CHOOSE) + 1);
		cout << ptr[i] << " ";
		i++;
	}

	cout << endl;

	// 수행시간 측정
	start = clock();
	std::sort(ptr, ptr + CHOOSE);
	stop = clock();

	// 정렬 후
	i = 0;

	cout << "정렬 후: ";

	while (i < CHOOSE)
	{
		cout << ptr[i] << " ";
		i++;
	}

	cout << endl;
	cout << "수행시간은 : " << (stop - start) / CLOCKS_PER_SEC;
}

void MenuOfAuto(int* ptr){

	int i;
	int sample[5] = { 1000, 5000, 10000, 50000, 100000 };
	int sample_size = sizeof(sample) / sizeof(int);
	
	double start, stop, estimate;

	// 파일 열기
	ofstream fp("result_cpp.txt");

	// 랜덤 활성화
	srand(time(NULL));

	// C언어 - QSort
	fp << "C++ - std::sort\n";
	i = 0;

	// Run
	while (i < sample_size)
	{
		ptr = new int[sample[i]];

		// printf("%d번\n", i);

		// 정렬 전
		// printf("정렬 전 :");
		for (int j = 0; j < sample[i]; j++){
			ptr[j] = (rand() % sample[i]) + 1;
			//printf("%d ", ptr[j]);
		} // end of for

		// printf("\n");

		start = (double)clock();
		std::sort(ptr, ptr + sample[i]);
		stop = (double)clock();

		/*
		// 정렬 후
		printf("정렬 후 :");
		for (int j = 0; j < sample[i]; j++)
		{
		printf("%d ", ptr[j]);
		} // end of for

		printf("\n");
		printf("\n");

		*/

		// printf("수행시간은 : %.2f", (stop - start) / CLOCKS_PER_SEC);
		estimate = (stop - start) / CLOCKS_PER_SEC;

		// 엑셀 추출 고려
		// 초기화(정렬전)
		fp << sample[i];
		fp << ",";
		fp << estimate;
		fp << "\n";

		delete ptr;		// 초기화 - ptr
		ptr = NULL;		// Safe Memory - pBuffer

		i++;

	} // end of while

	fp.close();

	cout << "\n";
	cout << "출력 파일: result_cpp.txt \n";
	cout << "\n";

}