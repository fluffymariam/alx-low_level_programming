#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char lowercase;
	char uppercase;

	lowercase = 'a';
	while (lowercase <= 'z')
	{
		putchar(lowercase);
		lowercase++;
	}
	uppercase = 'A';
	while (uppercase <= 'Z')
	{
		putchar(uppercase);
		uppercase++;
	}
	putchar('\n');
	return (0);
}
