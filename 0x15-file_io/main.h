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
void checkElf(unsigned char *ident);
void printMagic(unsigned char *ident);
void printClass(unsigned char *ident);
void printData(unsigned char *ident);
void printVersion(unsigned char *ident);
void printAbi(unsigned char *ident);
void printOsAbi(unsigned char *ident);
void printElfType(unsigned int type, unsigned char *ident);
void printEntryAddress(unsigned long int entry, unsigned char *ident);
void closeElf(int elfDescriptor);

#endif
