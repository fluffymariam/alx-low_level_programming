#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - creates a file and writes into it
 * @filename: name of file t create
 * @text_content: the content to write teh file
 * Return: 1 on success, -1 fail
 */

int create_file(const char *filename, char *text_content)
{
	FILE *mar;

	if (filename == NULL)
	{
		return (-1);
	}

	mar = fopen(filename, "w");

	if (mar == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		if (fputs(text_content, mar) == EOF)
		{
			fclose(mar);
			return (-1);
		}
	}
	fclose(mar);
	return (1);
}
