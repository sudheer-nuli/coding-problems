#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

int main()
{
	int n = 10, i, Lbound, Ubound, j, WaterStored = 0, temp, t, k, max, m;
	/*printf("Enter the size of the array\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Given values : ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}*/
	int a[] = { 5, 3, 7, 2, 6, 4, 5, 9, 1, 2 };
	Lbound = 0; Ubound = 0;
	do
	{
		int count = 0;
		for (i = Ubound + 1; i < n; i++)
		{
			if (a[i] > a[Lbound])
			{
				Ubound = i;
				t = Lbound;
				break;
			}

			else if (i == n - 1)
			{
				m = Lbound + 1;
				max = a[m];
				for (k = m; k < n; k++)
				{
					if (max <= a[k])
					{
						max = a[k];
						t = k;
						Ubound = k;

					}
				}
				break;
			}
			//count++;
		}
		count = Ubound - Lbound - 1;
		temp = a[t] * count;
		for (j = Lbound + 1; j < Ubound; j++)
		{
			temp = temp - a[j];
		}
		WaterStored += temp;
		Lbound = Ubound;
	} while (Lbound < n - 1);
	printf("WaterStored : %d", WaterStored);
	_getch();
	return 0;
}