#include <stdio.h>

#ifdef _WIN32

#include <fcntl.h>
#include <io.h>
#include "iwyu_getopt.h"

#else

#include <getopt.h>

#endif

#include "dump.h"
#include "buffer.h"

#define BUFFER_SIZE 2048

buffer read_all_stdin() {
    buffer out_data = make_buffer();
    
    char buffer[BUFFER_SIZE];
    
    size_t amount_read;
    while ((amount_read = fread(buffer, 1, BUFFER_SIZE, stdin)) > 0) {
        buffer_append(&out_data, buffer, amount_read);
    };

    if (ferror(stdin)) {
        perror("Could not read stdin");
        exit(3);
    }

    return out_data;
}

int main(int argc, char *argv[]) {

    int print_strings = 0;

    struct option long_options[] =
    {
        {"print-strings", no_argument, &print_strings, 1},
        {NULL, 0, NULL, 0}
    };

    while (getopt_long(argc, argv, "", long_options, NULL) != -1) {}

#ifdef _WIN32
    // Switch stdin to binary
    if (_setmode(_fileno(stdin), _O_BINARY) == -1) {
        perror("Could not switch stdin to binary");
        exit(1);
    }
#endif

    buffer b = read_all_stdin();
    dump_msgpack(b, print_strings);
    printf("\n");
}