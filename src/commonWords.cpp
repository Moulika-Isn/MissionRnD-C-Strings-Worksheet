/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

int length(char str[])
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
char ** commonWords(char *str1, char *str2) {
	char s1[31][10], s2[31][10];
	char **p;
	int i = 0, x = 0, y = 0, j = 0;
	int m, k = 0, s, t = 0, a;
	if (!(str1) || (str2))
		return NULL;
	i = length(str1);
	j = length(str2);
	for (m = 0; m <= i; m++)
	{
		if ((*(str1 + m) == ' ') || (*(str1 + m) == '\0'))
		{
			a = 0;
			for (k; k < m; k++)
			{
				s1[x][a] = *(str1 + k);
				a++;
			}
			s1[x][a] = '\0';
			k++;
			x++;
		}
	}
	k = 0;
    for (m = 0; m <= j; m++)
    {
        if ((*(str2 + m) == ' ') || (*(str2 + m) == '\0'))
        {
			a = 0;
            for (k; k < m; k++)
            {
                s2[y][a] = *(str2 + k);
                a++;
            }
            s2[y][a] = '\0';
            k++;
            y++;
        }
    }
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			a = 0;
			for (k = 0; s1[i][k] != '\0', s2[j][k] != '\0'; k++)
			{
				if (s1[i][k] != s2[j][k])
				{
					a = 1;
					break;
				}
			}
			if (a == 0)
			{
				for (m = 0; s1[i][m] != '\0'; m++)
					*(*(p + t) + m) = s1[i][m];
				*(*(p + t) + m) = '\0';
				t++;
			}
		}
	}
	return p;
	
}