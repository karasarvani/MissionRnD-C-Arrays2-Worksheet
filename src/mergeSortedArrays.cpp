/*	Write a function that produces a single merged statement ordered by dates.
	E.g. : Input : A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
		  B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
	  Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, 30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

	  INPUTS: Two bank statements(array of transactions).

	  OUTPUT : Combined statement ordered by transaction date.

			   ERROR CASES : Return NULL for invalid inputs.

		   NOTES :
				 */

#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

			  struct transaction {
				  int amount;
				  char date[11];
				  char description[20];
			  };
			  int conversion1(char *A, int i, int j)
			  {
				  int num = 0, index;
				  for (index = i; index <= j; index++)
				  {
					  num = num * 10 + (A[index] - 48);
				  }
				  return num;
			  }
			  int comparision(char *A, char *B)
			  {
				  int yy1, yy2, mm1, mm2, dd1, dd2;
				  yy1 = conversion1(A, 6, 9);
				  yy2 = conversion1(B, 6, 9);
				  mm1 = conversion1(A, 3, 4);
				  mm2 = conversion1(B, 3, 4);
				  dd1 = conversion1(A, 0, 1);
				  dd2 = conversion1(B, 0, 1);
				  if (yy1 == yy2)
				  {
					  if (mm1 == mm2)
					  {
						  if (dd1 == dd2)
							  return 1;
						  else if (dd1>dd2)
							  return 0;
						  else
							  return -1;

					  }
					  else if (mm1>mm2)
						  return 0;
					  else
						  return -1;
				  }
				  else if (yy1>yy2)
					  return 0;
				  else
					  return -1;
			  }
			  struct transaction *mergeSortedArrays(struct  transaction *A, int ALen, struct  transaction *B, int BLen){

				  int i = 0, j = 0, p = 0;
				  struct transaction *result;
				  if (A&&B&&ALen>0 && BLen>0)
				  {
					  result = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
					  for (p = 0; p< (ALen + BLen); p++)
					  {
						  if (i<ALen&&j<BLen)
						  {
							  if (comparision(A[i].date, B[j].date) == 0)
							  {
								  result[p] = B[j];
								  j++;
							  }
							  else
							  {
								  result[p] = A[i];
								  i++;
							  }
						  }
						  else
						  {
							  break;
						  }

					  }
					  if (j>BLen-1)
					  {

						  for (i = i; i<ALen; i++)
						  {
							  result[p++] = A[i];
						  }
					  }
					  else
					  {
						  for (j = j; j<BLen; j++)
						  {

							  result[p++] = B[j];
						  }
					  }
					  return result;
				  }
				  else{
					  return NULL;
				  }
			  }

