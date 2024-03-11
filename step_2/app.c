#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "macrofiles.h"

int strsize(char *str);
char *endfile(char *string);
int pointfinder(char *string);

int main(int argc, char *argv[])
{

    if (argc > 2)
    {
        printf("Error: more than one code file specified\n");
    }

    else if (argc == 2)
    {

        if (strcmp(argv[1], "--version") == 0)
        {
            printf("Ninja Virtual Machine version 2 Compiled %s at %s\n", __DATE__, __TIME__);
            exit(1);
        }

        else if (strcmp(argv[1], "--help") == 0)
        {
            printf("usage: ./njvm [option] <code file>\n");
            printf(" --version        show version and exit\n");
            printf(" --help           show this help and exit\n");
            exit(1);
        }

        else if (pointfinder(argv[1]) == 1)
        {
            if (strcmp(endfile(argv[1]), ".bin") == 0)
            {

                // the real work is written heres
                char buffer0[4];
                char format[5];
                unsigned int buffer1[3];
                FILE *file = NULL;
                file = fopen(argv[1], "rb");
                if (file != NULL)
                {

                    fread(buffer0, sizeof(char), 4, file); // read the first  bytes to our buffer
                    buffer0[5] = '\0';
                    for (int i = 0; i < 4; i++)
                    {
                        format[i] = buffer0[i];
                    }
                    format[4] = '\0';

                    // read to register step
                    fread(buffer1, sizeof(int), 3, file);

                    int *Register = malloc(sizeof(int) * buffer1[1]);

                    // format and version controll
                    if (strcmp(format, FILE_FORMAT) == 0 && (int)buffer1[0] == NJA_VERSION)
                    {
                        int PC = 0;
                        unsigned int IR = 0;
                        sp = 0;
                        fp = 0;
                        stack = malloc(sizeof(int) * CAPACITY);
                        if (buffer1[3] != 0)
                        {
                            sda = malloc(sizeof(int) * (int)buffer1[2]);
                        }
                        fread(Register, sizeof(int), (int)buffer1[1], file);
                        fclose(file);

                        printf("Ninja Virtual Machine started\n");

                        do
                        {
                            IR = Register[PC];
                            programlistner(PC, IR);
                            PC = PC + 1;
                        } while ((IR >> 24) != HALT);

                        PC = 0;
                        while (!HALT)
                        {
                            IR = Register[PC];
                            PC = PC + 1;
                            exe(IR);
                        }
                    }
                }
                else
                {
                    printf("Error: impossible to open the file %s ", argv[1]);
                }
            }
            else
            {
                printf("Error: file '%s' is not a Ninja binary\n", argv[1]);
            }
        }
        else
        {
            printf("Error: cannot open code file '%s' \n", argv[1]);
        }
    }

    else
    {
        printf("Error: no code  file specified\n");
    }

    return 0;
}

int pointfinder(char *string)
{
    int test = 0;
    int size = strsize(string);
    for (int i = 0; i < size; i++)
    {
        if (string[i] == '.')
        {
            test++;
            break;
        }
    }
    return test;
}
char *endfile(char *string)
{
    char *result = malloc(sizeof(char) * 5);
    int search = 0;
    int j = 0;
    int size = strsize(string);
    while (string[search] != '.')
    {
        search += 1;
    }
    for (int i = search; i < size; i++)
    {
        result[j] = string[i];
        j++;
    }
    result[4] = '\0';

    return result;
}
int strsize(char *str)
{
    int size = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        size += 1;
        i++;
    }
    return size;
}