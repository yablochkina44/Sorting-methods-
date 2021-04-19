#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <malloc.h>
#include <iso646.h>
#include<omp.h>
#include <wctype.h>

void masout(int p[], int N)//вывод массива
{
	for (int i = 0; i < N; i++)
	{
		printf("%d  ", p[i]);
	}
	printf("\n");
}
void ob(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void buble(int p[], int N)
{
	//пузырьковый
	int* m = new int[N];

	for (int i = 0; i < N; i++)
	{
		m[i] = p[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (m[j] > m[j + 1])
				ob(&m[j], &m[j + 1]);
		}
	}
	masout(m, N);
}
void sheyk(int m[], int N)
{
	//шейкер

	int* p = new int[N];

	for (int i = 0; i < N; i++)
	{
		p[i] = m[i];
	}

	int left = 0, right = N - 1, flag = 1, obm = 0, sravn = 0;
	while ((left < right) & (flag = 1))
	{
		for (int i = left; i < right; i++)
		{
			if (p[i] > p[i + 1])
			{
				ob(&p[i], &p[i + 1]);
				obm++;
				flag = 1;
			}
			sravn++;
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (p[i - 1] > p[i])
			{
				ob(&p[i], &p[i - 1]);
				obm++;
				flag = 1;
			}
			else
				flag = 0;
			sravn++;
		}
		left++;
	}

	masout(p, N);

	printf("ќпераций обмена было совершенно =%d  \n", obm);
	printf("ќпераций сравнени€ было совершенно =%d \n", sravn);

	//ob(&p[j], &p[j + 1]);
}
void insert_sort(int m[], int N)
{
	//вставками 
	int* p = new int[N];

	for (int i = 0; i < N; i++)
	{
		p[i] = m[i];
	}

	for (int i = 0; i < N; i++)
	{
		int k = i;
		while (k > 0 and p[k - 1] > p[k])
		{
			ob(&p[k - 1], &p[k]);
			k--;
		}
	}
	masout(p, N);
}
void countSort(int m[], int k)
{
	//подсчетом
	int* p = new int[k];

	for (int i = 0; i < k; i++)
	{
		p[i] = m[i];
	}

	long int* s;
	int i, max = p[0], n = 0, min = p[0], l;
	for (i = 0; i < k; i++) {
		if (p[i] > max)
			max = p[i];
		if (p[i] < min)
			min = p[i];
	}
	l = max - min + 1;
	s = (long int*)malloc(l * sizeof(long int));
	for (i = 0; i < l; i++) {
		s[i] = 0;
	}
	for (i = 0; i < k; i++) {
		s[p[i] - min]++;
	}
	for (i = 0; i < l; i++) {
		for (int j = 0; j < s[i]; j++)
		{
			p[n] = i + min;
			n++;
		}
	}
	free(s);

	masout(p, k);

	/*
	int* count, k = 0;
	count = (int*)malloc(N * sizeof(int));
	for (int i = 1; i < N; i++)
	{
		count[i] = 0;
	}
	for (int i = 0; i < s; i++)
	{
		count[p[i]]++;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= count[i]; j++)
		{
			if (count[i] != 0)

			{
				p[k] = i;
				count[i]--;
				k++;
			}
		}
	}
	free(count);

	printf("ќпераций сравнени€ было совершенно =%d \n", count);
	masout(p, N);
	*/
}
/*
void qsort(int m[], int f, int l)
{
	//быстра€


	int k = (f + l) / 2,  i = f, j = l;
	int* p = new int[k];

	for (int i = 0; i < k; i++)
	{
		p[i] = m[i];
	}
	int el = p[k];

	while (i < j)
	{
		while (p[i] < el) i++;
		while (p[j] > el) j--;
		if (i <= j)
		{
			ob(&p[i], &p[j]);
			i++;
			j--;
		}
	}
	if (f < j)
		qsort(p, f, j);
	if (i < l)
		qsort(p, i, l);

	masout(p,k);
	printf("\n");


}
*/

void qsort(int* p, int f, int l)

{
	int k = (f + l) / 2, el = p[k], i = f, j = l;

	while (i < j)
	{
		while (p[i] < el) i++;
		while (p[j] > el) j--;
		if (i <= j)
		{
			ob(&p[i], &p[j]);
			i++;
			j--;
		}
	}
	if (f < j) qsort(p, f, j);
	if (i < l) qsort(p, i, l);



}
void qqsort(int mas[], int f, int l)
{
	int* p = new int[f + l + 1];

	for (int v = 0; v < f + l + 1; v++)
	{
		p[v] = mas[v];
	}
	qsort(p, f, l);

	masout(p, f + l + 1);

}

void sel_Sort(int m[], int N)
{
	//выбор

	int* p = new int[N];

	for (int i = 0; i < N; i++)
	{
		p[i] = m[i];
	}

	int min;
	int sravn = 0, obmen = 0;
	for (int i = 0; i < N - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
		{
			sravn++;
			if (p[j] < p[min])
			{
				min = j;
			}
		}
		obmen++;
		ob(&p[i], &p[min]);
	}
	masout(p, N);
	printf("ќпераций обмена было совершенно =%d  \n", obmen);
	printf("ќпераций сравнени€ было совершенно =%d \n", sravn);
}

void merge(int arr[], int n, int s, int k)
{
	int i, j, t;
	int* p = (int*)malloc((k - n + 1) * sizeof(int));
	i = n; j = s + 1; t = 0;
	while ((i <= s) and (j <= k))
	{
		if (arr[i] < arr[j])
		{
			p[t] = arr[i]; t++; i++;
		}
		else
		{
			p[t] = arr[j]; t++; j++;
		}
	}
	if (i > s)
	{
		while (j <= k)
		{
			p[t] = arr[j];
			t++;
			j++;
		}
	}
	else
	{
		while (i <= s)
		{
			p[t] = arr[i];
			t++; i++;
		}
	}
	for (int i = 0; i <= k - n; i++)
	{
		arr[n + i] = p[i];
	}
	free(p);

}
void mergeSort(int mas[], int n, int k)
{

	int s = (n + k) / 2;
	if (n - k == 0)
		return;
	else
	{
		mergeSort(mas, n, s);
		mergeSort(mas, s + 1, k);
		merge(mas, n, s, k);
	}


}
void mergeSsort(int mas[], int n, int k)
{
	int* mass = new int[n + k];

	for (int i = 0; i < n + k + 1; i++)
	{
		mass[i] = mas[i];
	}

	mergeSort(mass, n, k);

	masout(mass, n + k + 1);

}


void searchLIN(int m[], int s, int el)
{

	int f = 0;
	int count = 0, i, id;
	for (i = 0; i < s; i++)
	{
		count += 1;
		if (m[i] == el)
		{
			id = i;
			f = 1;
			break;

		}
	}
	double end = omp_get_wtime();
	if (f == 1)
	{
		printf_s("»ндекс искомого элемента: %i\n", id);
	}
	else
	{
		printf_s("Ёлемент не найден\n");
	}


}
void searchBIN(int p[], int s, int el)
{

	int l = 0, h = s - 1, id, f = 0;
	qsort(p,0, s - 1);
	masout(p, s);
	printf("\n");
	while (l <= h and f != 1)
	{
		id = (l + h) / 2;
		if (el == p[id])
		{
			f = 1;
			break;
		}
		if (el > p[id])
		{
			l = id + 1;
		}
		else {
			h = id - 1;
		}
	}
	double end = omp_get_wtime();
	if (f == 1) {
		printf_s("»ндекс искомого элемента: %i\n", id);
	}
	else {
		printf_s("Ёлемент не найден\n");
	}
}









































void bublee(int p[], int N)
{
	//пузырьковый
	int* m = new int[N];

	for (int i = 0; i < N; i++)
	{
		m[i] = p[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (m[j] > m[j + 1])
				ob(&m[j], &m[j + 1]);
		}
	}
	
}
void sheykk(int m[], int N)
{
	//шейкер

	int* p = new int[N];

	for (int i = 0; i < N; i++)
	{
		p[i] = m[i];
	}

	int left = 0, right = N - 1, flag = 1, obm = 0, sravn = 0;
	while ((left < right) & (flag = 1))
	{
		for (int i = left; i < right; i++)
		{
			if (p[i] > p[i + 1])
			{
				ob(&p[i], &p[i + 1]);
				obm++;
				flag = 1;
			}
			sravn++;
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (p[i - 1] > p[i])
			{
				ob(&p[i], &p[i - 1]);
				obm++;
				flag = 1;
			}
			else
				flag = 0;
			sravn++;
		}
		left++;
	}

	

	
}
void insert_sortt(int m[], int N)
{
	//вставками 
	int* p = new int[N];

	for (int i = 0; i < N; i++)
	{
		p[i] = m[i];
	}

	for (int i = 0; i < N; i++)
	{
		int k = i;
		while (k > 0 and p[k - 1] > p[k])
		{
			ob(&p[k - 1], &p[k]);
			k--;
		}
	}
	
}
void countSortt(int m[], int k)
{
	//подсчетом
	int* p = new int[k];

	for (int i = 0; i < k; i++)
	{
		p[i] = m[i];
	}

	long int* s;
	int i, max = p[0], n = 0, min = p[0], l;
	for (i = 0; i < k; i++) {
		if (p[i] > max)
			max = p[i];
		if (p[i] < min)
			min = p[i];
	}
	l = max - min + 1;
	s = (long int*)malloc(l * sizeof(long int));
	for (i = 0; i < l; i++) {
		s[i] = 0;
	}
	for (i = 0; i < k; i++) {
		s[p[i] - min]++;
	}
	for (i = 0; i < l; i++) {
		for (int j = 0; j < s[i]; j++)
		{
			p[n] = i + min;
			n++;
		}
	}
	free(s);

	

	
}
void sel_Sortt(int m[], int N)
{
	//выбор

	int* p = new int[N];

	for (int i = 0; i < N; i++)
	{
		p[i] = m[i];
	}

	int min;
	int sravn = 0, obmen = 0;
	for (int i = 0; i < N - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
		{
			sravn++;
			if (p[j] < p[min])
			{
				min = j;
			}
		}
		obmen++;
		ob(&p[i], &p[min]);
	}
	
	
}
void qqsortt(int mas[], int f, int l)
{
	int* p = new int[f + l + 1];

	for (int v = 0; v < f + l + 1; v++)
	{
		p[v] = mas[v];
	}
	qsort(p, f, l);

}
void mergeSsortt(int mas[], int n, int k)
{
	int* mass = new int[n + k];

	for (int i = 0; i < n + k + 1; i++)
	{
		mass[i] = mas[i];
	}

	mergeSort(mass, n, k);



}