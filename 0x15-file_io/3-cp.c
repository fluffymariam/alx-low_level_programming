#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void print_error(char *message, char *file_name, int exit_code) {
dprintf(STDERR_FILENO, message, file_name);
exit(exit_code);
}

int main(int argc, char *argv[]) {
if (argc != 3) {
print_error("Usage: %s file_from file_to\n", argv[0], (97));
}

int file_from = open(argv[1], O_RDONLY);
if (file_from == -1) {
print_error("Error: Can't read from file %s\n", argv[1], (98));
}

int file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (file_to == -1) {
print_error("Error: Can't write to %s\n", argv[2], (99));
}

char buffer[1024];
ssize_t bytes_read, bytes_written;

while ((bytes_read = read(file_from, buffer, sizeof(buffer))) > 0) {
bytes_written = write(file_to, buffer, bytes_read);
if (bytes_written == -1) {
print_error("Error: Can't write to %s\n", argv[2], (99));
}
}

if (bytes_read == -1) {
print_error("Error reading from file %s\n", argv[1], (98));
}

if (close(file_from) == -1) {
print_error("Error: Can't close fd %d\n", (char*)argv[1], (100));
}

if (close(file_to) == -1) {
print_error("Error: Can't close fd %d\n", (char*)argv[2], (100));
}

return (0);
}
