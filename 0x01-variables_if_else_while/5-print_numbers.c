#include <stdio.h>
#include <unistd.h>

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
		printf("%d ", num);
		num++;
	}

	printf("\n");
	return (0);
}
