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
		cout << "OOOOOOOOOOOOOOOOOOO��" << endl;
		cout << "Dept. Business and Computer Software Engineering" << endl;
		cout << "C++ std::sort" << endl;
		cout << "��OO(OOOOOOOOOOOOOO Jeong)" << endl;
		cout << "1�� ��������" << endl;
		cout << "2�� �ڵ�����" << endl;
		cout << "0�� Ż��" << endl;
		cout << "�޴��� �����ϼ��� : ";

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
		cout << "���ڸ� �Է��ϼ��� : ";
		cin >> CHOOSE;

		if (CHOOSE <= 0)
			cout << "���� ������" << endl;
		else
			break;

	} // end of while

	ptr = new int[CHOOSE];

	// ���� Ȱ��ȭ
	srand(time(NULL));

	i = 0;

	// ���� ��
	cout << "���� ��: ";

	while (i < CHOOSE)
	{
		ptr[i] = ((rand() % CHOOSE) + 1);
		cout << ptr[i] << " ";
		i++;
	}

	cout << endl;

	// ����ð� ����
	start = clock();
	std::sort(ptr, ptr + CHOOSE);
	stop = clock();

	// ���� ��
	i = 0;

	cout << "���� ��: ";

	while (i < CHOOSE)
	{
		cout << ptr[i] << " ";
		i++;
	}

	cout << endl;
	cout << "����ð��� : " << (stop - start) / CLOCKS_PER_SEC;
}

void MenuOfAuto(int* ptr){

	int i;
	int sample[5] = { 1000, 5000, 10000, 50000, 100000 };
	int sample_size = sizeof(sample) / sizeof(int);
	
	double start, stop, estimate;

	// ���� ����
	ofstream fp("result_cpp.txt");

	// ���� Ȱ��ȭ
	srand(time(NULL));

	// C��� - QSort
	fp << "C++ - std::sort\n";
	i = 0;

	// Run
	while (i < sample_size)
	{
		ptr = new int[sample[i]];

		// printf("%d��\n", i);

		// ���� ��
		// printf("���� �� :");
		for (int j = 0; j < sample[i]; j++){
			ptr[j] = (rand() % sample[i]) + 1;
			//printf("%d ", ptr[j]);
		} // end of for

		// printf("\n");

		start = (double)clock();
		std::sort(ptr, ptr + sample[i]);
		stop = (double)clock();

		/*
		// ���� ��
		printf("���� �� :");
		for (int j = 0; j < sample[i]; j++)
		{
		printf("%d ", ptr[j]);
		} // end of for

		printf("\n");
		printf("\n");

		*/

		// printf("����ð��� : %.2f", (stop - start) / CLOCKS_PER_SEC);
		estimate = (stop - start) / CLOCKS_PER_SEC;

		// ���� ���� ���
		// �ʱ�ȭ(������)
		fp << sample[i];
		fp << ",";
		fp << estimate;
		fp << "\n";

		delete ptr;		// �ʱ�ȭ - ptr
		ptr = NULL;		// Safe Memory - pBuffer

		i++;

	} // end of while

	fp.close();

	cout << "\n";
	cout << "��� ����: result_cpp.txt \n";
	cout << "\n";

}