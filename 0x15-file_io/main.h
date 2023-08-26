#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
ssize_t _write(int fd, const char *str, size_t len);
void _putchar(char c);
void print_error(const char *message);
void print_elf_header_info(const Elf64_Ehdr *header);
int main(int argc, char *argv[]);

#endif
