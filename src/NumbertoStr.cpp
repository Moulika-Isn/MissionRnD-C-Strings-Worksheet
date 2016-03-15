/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

float power(float n, int p)
{
	int i;
	for (i = 1; i <= p; i++)
		n = n * 10;
	return n;
}
int toString(char s[],int n,int sign)
{
	int num = n, i = 0, p, j;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (sign == 0)
	{
		p = i; 
		j = i - 1;
		for (i=j; i >= 0; i--)
		{
			s[i] = (num % 10) + '0';
			num = num / 10;
		}
	}
	else
	{
		p = i + 1;
		for (i; i > 0; i--)
		{
			s[i] = (num % 10) + '0';
			num = num / 10;
		}
		s[0] = '-';
	}
	s[p] = '\0';
	return p;
}
void number_to_str(float number, char *str, int afterdecimal){
	
	int i=0, x, y, sign, d, e, f;
	float n;
	char s[10];
	if (number < 0)
	{
		sign = 1;
		number = number*-1;
	}
	else
		sign = 0;
	if (afterdecimal == 0)
		x = (int)number; 
	if (number - (int)number == 0)
		x = (int)number;
	else
	{
		x = (int)number;
		n = number - (float)x;
		y = (int)power(n, afterdecimal);
	}
	d=toString(str, x, sign);
	if (afterdecimal == 0)
		return;
	else if (afterdecimal > 0)
	{
		e=toString(s, y, 0);
		i = 0;
		f = d + e;
		*(str + d) = '.';
		d++;
		for (d; d <= f; d++)
			*(str + d) = s[i++];
		*(str + d) = '\0';
	}
	return;
}