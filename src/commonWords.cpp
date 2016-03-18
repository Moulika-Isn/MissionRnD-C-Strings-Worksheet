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

int word_count(char *s)
{
	int i, count = 0;
	for (i = 0; s[i]; i++)
	{
		if ((s[i + 1] == ' ' || s[i + 1] == '\0') && (i - 1) >= 0 && s[i] != ' ')
		{
			++count;
		}
	}
	return count;
}
int isSame(char *p, char *q)
{
	int i;
	for (i = 0; p[i] && q[i]; i++)
	{
		if (p[i] != q[i]){
			return 0;
		}
	}
	if (p[i] == '\0'&&q[i] == '\0')
		return 1;
	return 0;

}
void stringCopy(char *p, char *q)
{
	int i;
	for (i = 0; q[i]; i++){
		p[i] = q[i];
	}
	p[i] = '\0';
}
char** extractWord(char *str1, int w)
{
	int i, j, k, s=0, e, r=0;
	char **str;
	str = (char **)malloc(w*sizeof(char *));
	for (i = 0; i < w; i++){
		str[i] = (char *)malloc(SIZE*sizeof(char));
	}
	for (i = 0; str1[i]; i++)
	{
		e = 0;
		if ((str1[i + 1] == ' ' || str1[i + 1] == '\0'))
		{
			e = i;
		}
		if (e != 0)
		{
			for (j = s, k = 0; j <= e; j++)
			{
				if (str1[j] != ' ')
				{
					str[r][k] = str1[j];
					k++;
				}
			}
			str[r][k] = '\0';
			s = e + 2;
			if (k != 0)
				r++;
		}
	}
	return str;
}
char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	int i, j, w1 = 0, w2 = 0, s = 0, e = 0, r = 0;
	int cw;
	char **s1, **s2, **s3;
	w1 = word_count(str1);
	w2 = word_count(str2);
    if (w1 == 0 || w2 == 0)
		return NULL;
	s1 = (char **)malloc(w1*sizeof(char *));
	for (i = 0; i < w1; i++)
		s1[i] = (char *)malloc(SIZE*sizeof(char));
	s2 = (char **)malloc(w2*sizeof(char *));
	for (i = 0; i < w1; i++)
		s2[i] = (char *)malloc(SIZE*sizeof(char));
	s3 = (char **)malloc(w1*sizeof(char *));
	for (i = 0; i < w1; i++)
		s3[i] = (char *)malloc(SIZE*sizeof(char));
	s1 = extractWord(str1, w1);
	s2 = extractWord(str2, w2);
	cw = 0;
	for (i = 0; i < w1; i++)
	{
		for (j = 0; j < w2; j++)
		{
			if (isSame(s1[i], s2[j]))
			{
				stringCopy(s3[cw++], s1[i]);
			}
		}
	}
	if (cw == 0)
		return NULL;

	return s3;
}