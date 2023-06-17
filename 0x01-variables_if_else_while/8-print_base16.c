#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int num = 0;

	while (num < 10)
	{
		putchar(num + '0');
		num++;
	}

	num = 'a';

	while (num <= 'f')
	{
		putchar(num);
		num++;
	}

	putchar('\n');

	return (0);
}
