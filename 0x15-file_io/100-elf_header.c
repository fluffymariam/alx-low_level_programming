#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void error_exit(const char *message, const char *filename, int code);
void print_elf_header(Elf64_Ehdr *girl);

void error_exit(const char *message, const char *filename, int code)
{
dprintf(STDERR_FILENO, message, filename);
exit(code);
}

void print_elf_header(Elf64_Ehdr *girl)
{
int i;

printf("ELF Header:\n");
printf("Magic: ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x ", girl->e_ident[i]);
printf("\n");
printf("Class: %s\n", (girl->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
printf("Data: %s\n", (girl->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" :
(girl->e_ident[EI_DATA] == ELFDATA2MSB) ? "2's complement, big endian" : "Unknown");
printf("Version: %d (current)\n", girl->e_ident[EI_VERSION]);
printf("OS/ABI: ");
switch (girl->e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
default:
printf("<unknown: %d>\n", girl->e_ident[EI_OSABI]);
break;
}
printf("ABI Version: %d\n", girl->e_ident[EI_ABIVERSION]);
printf("Type: ");
switch (girl->e_type)
{
case ET_NONE:
printf("NONE (Unknown type)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
default:
printf("<unknown: %d>\n", girl->e_type);
break;
}
printf("Entry point address: 0x%lx\n", (unsigned long)girl->e_entry);
}

int main(int argc, char *argv[])
{
int fd;
Elf64_Ehdr girl;
ssize_t bytes_read;

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
error_exit("Error: Cannot open file %s\n", argv[1], 98);

bytes_read = read(fd, &girl, sizeof(girl));
if (bytes_read != sizeof(girl))
{
close(fd);
error_exit("Error: Cannot read ELF header from file %s\n", argv[1], 98);
}

close(fd);

print_elf_header(&girl);

return 0;
}
