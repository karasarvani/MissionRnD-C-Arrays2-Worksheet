/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int verify_greater(char *str, int index_arr, char *date)
{
	int index;
	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] != date[index])
		{
			return -1;
		}
	}
	if (str[index] == '\0' && date[index] == '\0')
		return index_arr;
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int index, result, prev_result = -1;
	if (Arr&&date&&len>0)
	{
		for (index = 0; index<len; index++)
		{
			result = verify_greater(Arr[index].date, index, date);
			if ((prev_result >= 0) && (result == -1))
			{
				result = prev_result;
				break;
			}
			prev_result = result;
		}
		if (result == -1 || result == len - 1)
		{
			return 0;
		}
		else
		{
			return len - result - 1;
		}
	}
	else
		return -1;

}


