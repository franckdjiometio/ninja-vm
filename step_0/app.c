#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            printf("usage: %s [option] [option] ...\n", argv[0]);
            printf("\t--version        show version and exit\n");
            printf("\t-h, --help       show this message and exit\n");
        } else if (strcmp(argv[1], "--version") == 0) {
            printf("Ninja Virtual Machine version 0 (compiled Feb 14 2024, 19:30:52)\n");
        } else {
            printf("Ninja Virtual Machine: invalid option -- '%s'\n", argv[1]);
            printf("Try '%s --help' for more information.\n", argv[0]);
        }
    } else {
        printf("Ninja Virtual Machine started\n");

        printf("Ninja Virtual Machine stopped\n");
    }
    return 0;
}
