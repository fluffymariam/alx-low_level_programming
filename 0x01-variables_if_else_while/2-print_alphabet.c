#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - Prints the alphabeths in lower case
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		putchar(letter);
		letter++;
	}
	putchar('\n');
	return (0);
}
