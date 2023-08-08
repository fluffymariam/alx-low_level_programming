#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

#define ELF_HEADER_SIZE 64

typedef struct Elf64_Ehdr
{
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

void print_elf_header_info(Elf64_Ehdr *elf_header)
{
    int m;

    printf("ELF Header:\n");
    printf("  Magic: ");
    for (m = 0; m < 16; m++)
        printf("%02x ", elf_header->e_ident[m]);
    printf("\n  Class: ");
    switch (elf_header->e_ident[4])
    {
    case 1:
        printf("ELF32\n");
        break;
    case 2:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %02x>\n", elf_header->e_ident[4]);
        break;
    }
    printf("  Data: 2's complement, %s\n",
           elf_header->e_ident[5] == 1 ? "little endian" : "big endian");
    printf("  Version: %d (current)\n", elf_header->e_version);
    printf("  OS/ABI: ");
    switch (elf_header->e_ident[7])
    {
    case 0:
        printf("UNIX - System V\n");
        break;
    case 6:
        printf("UNIX - Solaris\n");
        break;
    case 9:
        printf("UNIX - NetBSD\n");
        break;
    default:
        printf("<unknown: %d>\n", elf_header->e_ident[7]);
        break;
    }
    printf("  ABI Version: %d\n", elf_header->e_ident[8]);
    printf("  Type: ");
    switch (elf_header->e_type)
    {
    case 1:
        printf("REL (Relocatable file)\n");
        break;
    case 2:
        printf("EXEC (Executable file)\n");
        break;
    case 3:
        printf("DYN (Shared object file)\n");
        break;
    default:
        printf("<unknown: %d>\n", elf_header->e_type);
        break;
    }
    printf("  Entry point address: 0x%lx\n", elf_header->e_entry);
}

int main(int argc, char *argv[])
{
    Elf64_Ehdr elf_header;
    int mar;
    ssize_t bytes_read;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    mar = open(argv[1], O_RDONLY);
    if (mar == -1)
    {
        fprintf(stderr, "Error: Unable to open the file %s\n", argv[1]);
        exit(98);
    }

    bytes_read = read(mar, &elf_header, sizeof(elf_header));
    if (bytes_read != sizeof(elf_header))
    {
        fprintf(stderr, "Error: Unable to read ELF header from file %s\n", argv[1]);
        close(mar);
        exit(98);
    }

    if (elf_header.e_ident[0] != 0x7f || elf_header.e_ident[1] != 'E' ||
        elf_header.e_ident[2] != 'L' || elf_header.e_ident[3] != 'F')
    {
        fprintf(stderr, "Error: Not an ELF file - Invalid ELF magic number\n");
        close(mar);
        exit(98);
    }

    print_elf_header_info(&elf_header);

    close(mar);
    return 0;
}
