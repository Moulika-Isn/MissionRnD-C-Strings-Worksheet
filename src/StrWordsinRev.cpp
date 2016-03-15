/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void swap(char *p, char *q)
{
	char temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
void reverse(char str[])
{
	int i = 0, j, k = 0;
	int m = 0, n;
	while (str[i] != '\0')
	{
		if (str[i] == 32)
		{
			m = 1;
			n = (i - k) / 2;
			for (j = k; m <= n; j++)
			{
				swap(&str[j], &str[i - m]);
				m++;
			}
			k = i + 1;

		}
		i++;
	}
	m = 1;
	n = (i - k) / 2;
	for (j = k; m <= n; j++)
	{
		swap(&str[j], &str[i - m]);
		m++;
	}
}
void str_words_in_rev(char *input, int len){
	int i = 0;
	for (i = 0; i < len / 2; i++)
		swap(input + i, input + len - i - 1);
	reverse(input);
}
