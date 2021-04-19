#include <stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#include <malloc.h>
#include <iso646.h>
#include <time.h>
#include<omp.h>
#include <wctype.h>
#include"functions.h"

//#define SIZE  10

void main()
{
	setlocale(LC_ALL, "Ru");
	srand(time(0));

	int s; int namber = 1; int el;
	double end, start;

	
	printf("Введите количество элементов массива\n");
	scanf_s("%d", &s);
	
	int* arr = new int[s];
	while (namber !=-1)
	{
		printf("\n\n*****************************\n");
		printf("*****************************\n");
		
		printf("Выберите команду\n");
		printf("0.  Вывод массива \n");
		printf("1.  Ввод массива \n");
		printf("2.  Рандомный ввод \n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("3.  Сортировка пузырьком \n");
		printf("4.  Сортировка шейкер \n");
		printf("5.  Сортировка вставками \n");
		printf("6.  Сортировка выбором \n");
		printf("7.  Сортировка подсчетом \n");
		printf("8.  Быстрая сортировка \n");
		printf("9.  Сортировка слиянием \n");
		printf("10. Сравнить сортировки \n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("11. Линейный поиск \n");
		printf("12. Бинарный поиск \n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("13. Очистить массив \n");
		printf("14. Exit \n");
		printf("*****************************\n");
		printf("*****************************\n");
		scanf_s("%d", &namber);
		printf("\n");
		switch (namber)
		{
		 case 0:
		   masout(arr, s);
		   break;
		 case 1:

			
			arr = (int*)malloc(s * sizeof(int));
			printf("Введите массив\n");
			for (int i = 0; i < s; i++)
			{
				scanf_s("%d", &arr[i]);
			}
			break;
		 case 2:
			arr = (int*)malloc(s * sizeof(int));
			for (int i = 0; i < s; i++)
			{
				arr[i]= rand() % 101;
			}
			break;
	
		 case 3:
			 masout(arr, s);
			 start = omp_get_wtime();
			 buble(arr, s);
			 end = omp_get_wtime();
			// printt(arr, s);
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			
			 break;
		 case 4:
			 masout(arr, s);
			 start = omp_get_wtime();
			 sheyk(arr, s);
			 end = omp_get_wtime();
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);

			 break;
		 case 5:
			 masout(arr, s);
			 start = omp_get_wtime();
			 insert_sort(arr, s);
			 end = omp_get_wtime();
			 
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 
			 break;
		 case 6:
			 masout(arr, s);
			 start = omp_get_wtime();
			 sel_Sort(arr, s);
			 end = omp_get_wtime();
			 
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 
			 break;
		 case 7:
			 masout(arr, s);
			 start = omp_get_wtime();
			 countSort(arr, s);
			 end = omp_get_wtime();
			 
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);

			 break;
		 case 8:
			 masout(arr, s);
			 
			 start = omp_get_wtime();
			 qqsort(arr, 0,s-1 );
			 end = omp_get_wtime();
			 
			 printf("Время выполнения: %.16g (сек) \n", end - start);
			 break;
		 case 9:
			 masout(arr, s);
	
			 start = omp_get_wtime();
			 mergeSsort(arr, 0, s-1);
			 end = omp_get_wtime();
			 
			 printf("Время выполнения: %.16g (сек) \n", end - start);
			 break;
		 case 10:

			 printf("**********************************************************\n");
			 printf_s("Сортировка пузырьком\n\n");
			 start = omp_get_wtime();
			 bublee(arr, s);
			 end = omp_get_wtime();
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 printf("**********************************************************\n\n\n");

			 printf("**********************************************************\n");
			 printf_s("Шейкер\n\n");
			 start = omp_get_wtime();
			 sheykk(arr, s);
			 end = omp_get_wtime();
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 printf("**********************************************************\n\n\n");

			 printf("**********************************************************\n");
			 printf_s("Сортировка вставками\n\n");
			 start = omp_get_wtime();
			 insert_sortt(arr, s);
			 end = omp_get_wtime();
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 printf("**********************************************************\n\n\n");

			 printf("**********************************************************\n");
			 printf_s("Сортировка выбором\n\n");
			 start = omp_get_wtime();
			 sel_Sortt(arr, s);
			 end = omp_get_wtime();
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 printf("**********************************************************\n\n\n");

			 printf("**********************************************************\n");
			 printf_s("Сортировка подсчетом\n\n");
			 start = omp_get_wtime();
			 countSortt(arr, s);
			 end = omp_get_wtime();
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 printf("**********************************************************\n\n\n");

			 printf("**********************************************************\n");
			 printf_s("Быстрая сортировка\n\n");
			 start = omp_get_wtime();
			 qqsortt(arr, 0,s-1);
			 end = omp_get_wtime();
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 printf("**********************************************************\n\n\n");

			 printf("**********************************************************\n");
			 printf_s("Сортировка слиянием\n\n");
			 start = omp_get_wtime();
			 mergeSsortt(arr,0, s-1);
			 end = omp_get_wtime();
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 printf("**********************************************************\n\n\n");



			 break;

		 case 11:
			 //линейный поиск
			 printf_s("Введите элемент\n");
			 start = omp_get_wtime();
			 scanf_s("%d", &el);
			 searchLIN(arr, s, el);
			 end = omp_get_wtime();
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 break;
		 case 12:
			 //бинарный поиск
			 printf_s("Введите искомый элемент ");
			 start = omp_get_wtime();
			 scanf_s("%i", &el);
			 searchLIN(arr, s, el);
			 end = omp_get_wtime();
			 printf_s("Время выполнения: %.16g (сек) \n", end - start);
			 break;
		 case 13:
			 free(arr);
			 break;
		 case 14:
			 
			 namber = -1;
			 break;
		 default:
		
			printf("Такой команды не существует :)");
			break;
		
		}
	}
}