#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define MENU_MANUAL 1
#define MENU_AUTO 2
#define MENU_EXIT 0

int compare(void *first_ptr, void *second_ptr)
{
	if (*(int*)first_ptr > *(int*)second_ptr)
		return 1;
	else if (*(int*) first_ptr < *(int*) second_ptr)
		return -1;
	else
		return 0;
}


void MenuOfManual(int* ptr);
void MenuOfAuto(int* ptr);

main()
{
	int CHOOSE;
	int *ptr = NULL;

	while (1)
	{
		printf("OOOOOOOOOOOOOOO��\n");
		printf("Dept. Business and Computer Software Engineering\n");
		printf("��OO(OOOOOOOO Jeong)\n");
		printf("C��� - qsort ���� �׽�Ʈ\n");
		printf("1�� ��������\n");
		printf("2�� �ڵ�����\n");
		printf("0�� Ż��\n");
		printf("�޴��� �����ϼ��� : ");

		scanf_s("%d", &CHOOSE);

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
		printf("���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &CHOOSE);

		if (CHOOSE <= 0)
			printf("���� ������\n");
		else
			break;

	} // end of while

	ptr = (int*)malloc(sizeof(int)* CHOOSE);

	// ���� Ȱ��ȭ
	srand(time(NULL));

	i = 0;

	// ���� ��
	printf("���� ��: ");

	while (i < CHOOSE)
	{
		ptr[i] = ((rand() % CHOOSE) + 1);
		printf("%d ", ptr[i]);
		i++;
	}

	// ����ð� ����
	start = clock();
	qsort(ptr, CHOOSE, sizeof(int), compare);
	stop = clock();

	// ���� ��
	i = 0;
	
	printf("���� ��: ");

	while (i < CHOOSE)
	{
		printf("%d ", ptr[i]);
		i++;
	}
	
	printf("\n");
	printf("����ð��� : %.2f", (stop - start) / CLOCKS_PER_SEC);
}

void MenuOfAuto(int* ptr){

	int i;
	int sample[5] = { 1000, 5000, 10000, 50000, 100000 };
	int sample_size = sizeof(sample) / sizeof(int);
	int dec, sign;

	char* pBuffer = NULL;
	double start, stop, estimate;
	
	// ���� ����
	FILE *fp = (FILE*) malloc (sizeof(FILE));
	fopen_s(&fp, "result_c.txt", "w");

	// ���� Ȱ��ȭ
	srand(time(NULL));

	// C��� - QSort
	fprintf_s(fp, "C��� - QSort\n");
	i = 0;

	// Run
	while (i < sample_size)
	{
		ptr = (int*)malloc(sizeof(int)* sample[i]);
		
		// printf("%d��\n", i);

		// ���� ��
		// printf("���� �� :");
		for (int j = 0; j < sample[i]; j++){
			ptr[j] = (rand() % sample[i]) + 1;
			//printf("%d ", ptr[j]);
		} // end of for

		// printf("\n");
		
		start = (double)clock();
		qsort(ptr, sample[i], sizeof(int), compare);
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
		pBuffer = (char*)malloc(sizeof(char)* CHAR_MAX);
		sprintf_s(pBuffer, CHAR_MAX, "%d", sample[i]);
		fprintf(fp, pBuffer);
		fprintf(fp, ",");
		
		free(pBuffer);

		// �ʱ�ȭ(������)
		pBuffer = (char*)malloc(sizeof(char)* CHAR_MAX);
		sprintf_s(pBuffer, CHAR_MAX, "%.2f", estimate);
		fprintf(fp, pBuffer);
		fprintf(fp, "\n");

		free(ptr);		// �ʱ�ȭ - ptr
		ptr = NULL;		// Safe Memory - pBuffer
		free(pBuffer);	// �ʱ�ȭ - pBuffer
		pBuffer = NULL; // Safe Memory - pBuffer

		i++;

	} // end of while

	fclose(fp);

	printf("\n");
	printf("��� ����: result_c.txt \n");
	printf("\n");

}