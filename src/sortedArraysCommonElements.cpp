/*
OVERVIEW: You are given 2 bank statements that are ordered by date.
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int conversion(char *A, int i, int j)
{
	int num = 0, index;
	for (index = i; index <=j; index++)
	{
		num = num * 10 + (A[index] - 48);
	}
	return num;
}
int comparision_of_dates(char *A, char *B)
{
	int yy1, yy2, mm1, mm2, dd1, dd2;
	yy1 = conversion(A, 6, 9);
	yy2 = conversion(B, 6, 9);
	mm1 = conversion(A, 3, 4);
	mm2 = conversion(B, 3, 4);
	dd1 = conversion(A, 0, 1);
	dd2 = conversion(B, 0, 1);
	if (yy1 == yy2)
	{
		if (mm1 == mm2)
		{
			if (dd1 == dd2)
				return 0;
			else if (dd1>dd2)
				return 1;
			else
				return -1;

		}
		else if (mm1>mm2)
			return 1;
		else
			return -1;
	}
	else if (yy1>yy2)
		return 1;
	else
		return -1;
}
int binary_search(struct transaction *A, int ALen, struct transaction B)
{
	int first = 0, result, middle;
	int last = ALen - 1;
	middle = (first + last) / 2;

	while (first <= last) {
		result = comparision_of_dates(A[middle].date, B.date);
		if (result == -1)
			first = middle + 1;
		else if (result == 0) {
			return 1;
			break;
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	if (first > last)
		return 0;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int index, result, k = 0;
	struct transaction *res;
	if (A&&B&&ALen>0 && BLen>0)
	{
		res = (struct transaction *)malloc(sizeof(struct transaction) * 1);
		for (index = 0; index<BLen; index++)
		{
			result = binary_search(A, ALen, B[index]);
			if (result == 1)
			{
				res = (struct transaction *)realloc(res, sizeof(struct transaction)*(k + 1));
				res[k] = B[index];
				k++;
			}
		}
		if (k == 0)
			return NULL;
		else
			return res;
	}
	else
		return NULL;
}