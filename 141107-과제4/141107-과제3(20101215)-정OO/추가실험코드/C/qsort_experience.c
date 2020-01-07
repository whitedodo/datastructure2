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
		printf("OOOOOOOOOOOOOOO교\n");
		printf("Dept. Business and Computer Software Engineering\n");
		printf("정OO(OOOOOOOO Jeong)\n");
		printf("C언어 - qsort 성능 테스트\n");
		printf("1번 수동조작\n");
		printf("2번 자동조작\n");
		printf("0번 탈출\n");
		printf("메뉴를 선택하세요 : ");

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
		printf("숫자를 입력하세요 : ");
		scanf_s("%d", &CHOOSE);

		if (CHOOSE <= 0)
			printf("음수 미지원\n");
		else
			break;

	} // end of while

	ptr = (int*)malloc(sizeof(int)* CHOOSE);

	// 랜덤 활성화
	srand(time(NULL));

	i = 0;

	// 정렬 전
	printf("정렬 전: ");

	while (i < CHOOSE)
	{
		ptr[i] = ((rand() % CHOOSE) + 1);
		printf("%d ", ptr[i]);
		i++;
	}

	// 수행시간 측정
	start = clock();
	qsort(ptr, CHOOSE, sizeof(int), compare);
	stop = clock();

	// 정렬 후
	i = 0;
	
	printf("정렬 후: ");

	while (i < CHOOSE)
	{
		printf("%d ", ptr[i]);
		i++;
	}
	
	printf("\n");
	printf("수행시간은 : %.2f", (stop - start) / CLOCKS_PER_SEC);
}

void MenuOfAuto(int* ptr){

	int i;
	int sample[5] = { 1000, 5000, 10000, 50000, 100000 };
	int sample_size = sizeof(sample) / sizeof(int);
	int dec, sign;

	char* pBuffer = NULL;
	double start, stop, estimate;
	
	// 파일 열기
	FILE *fp = (FILE*) malloc (sizeof(FILE));
	fopen_s(&fp, "result_c.txt", "w");

	// 랜덤 활성화
	srand(time(NULL));

	// C언어 - QSort
	fprintf_s(fp, "C언어 - QSort\n");
	i = 0;

	// Run
	while (i < sample_size)
	{
		ptr = (int*)malloc(sizeof(int)* sample[i]);
		
		// printf("%d번\n", i);

		// 정렬 전
		// printf("정렬 전 :");
		for (int j = 0; j < sample[i]; j++){
			ptr[j] = (rand() % sample[i]) + 1;
			//printf("%d ", ptr[j]);
		} // end of for

		// printf("\n");
		
		start = (double)clock();
		qsort(ptr, sample[i], sizeof(int), compare);
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
		pBuffer = (char*)malloc(sizeof(char)* CHAR_MAX);
		sprintf_s(pBuffer, CHAR_MAX, "%d", sample[i]);
		fprintf(fp, pBuffer);
		fprintf(fp, ",");
		
		free(pBuffer);

		// 초기화(정렬후)
		pBuffer = (char*)malloc(sizeof(char)* CHAR_MAX);
		sprintf_s(pBuffer, CHAR_MAX, "%.2f", estimate);
		fprintf(fp, pBuffer);
		fprintf(fp, "\n");

		free(ptr);		// 초기화 - ptr
		ptr = NULL;		// Safe Memory - pBuffer
		free(pBuffer);	// 초기화 - pBuffer
		pBuffer = NULL; // Safe Memory - pBuffer

		i++;

	} // end of while

	fclose(fp);

	printf("\n");
	printf("출력 파일: result_c.txt \n");
	printf("\n");

}