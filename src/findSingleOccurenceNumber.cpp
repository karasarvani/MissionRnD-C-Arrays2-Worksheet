/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<malloc.h>
void merge(int *arr, int l, int m, int r)
{
	int i, j, k, n1 = m - l + 1, n2 = r - m;
	int *L, *R;
	L = (int*)malloc(sizeof(int)*n1);
	R = (int*)malloc(sizeof(int)*n2);
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int *arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
int findSingleOccurenceNumber(int *A, int len) {
	int index = 0, count = 0;
	if (A&&len>0)
	{
		mergeSort(A, 0, len - 1);
		for (index = 0; index<len - 3;)
		{
			if (A[index] != A[index + 2])
			{
				return A[index];
				break;
			}
			index = index + 3;
		}
		if (index >= len - 3)
			return A[len - 1];
	}
	else
		return -1;
}