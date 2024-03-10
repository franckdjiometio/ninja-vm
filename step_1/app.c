#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "macrofiles.h"

int main(int argc, char* argv[]) {

    if (argc > 1) {
        if(strcmp(argv[1], "--prog1") == 0){
            unsigned int IR = 0;
            int PC = 0;
            printf("Ninja Virtual Machine started\n");
            unsigned int code1[] = {
               (PUSHC << 24) | IMMEDIATE(3),
               (PUSHC << 24) | IMMEDIATE(4),
               (ADD << 24),   
               (PUSHC << 24) | IMMEDIATE(10),
               (PUSHC << 24) | IMMEDIATE(6),
               (SUB << 24),   
               (MUL << 24),
               (WRINT << 24),
               (PUSHC << 24) | IMMEDIATE(10),
               (WRCHR << 24),
               (HALT << 24)
            };
            
            do {
                IR = code1[PC];
                programlistner(PC, IR); 
                PC = PC + 1; 
            } while((IR >> 24) != HALT);
              
            PC = 0;

            while(!HALT) {
                IR = code1[PC];
                PC = PC + 1;
                exe(IR);
            }

            printf("Ninja Virtual Machine stopped\n");

        } else if(strcmp(argv[1], "--prog2") == 0) {
            unsigned int IR = 0;
            int PC = 0;
            printf("Ninja Virtual Machine started\n");

            unsigned int code2[] = {
                (PUSHC << 24) | IMMEDIATE(-2),
                (RDINT << 24),
                (MUL << 24),
                (PUSHC << 24) | IMMEDIATE(3),
                (ADD << 24),
                (WRINT << 24),
                (PUSHC << 24) | IMMEDIATE('\n'),
                (WRCHR << 24),
                (HALT)
            };

            do {
                IR = code2[PC];
                programlistner(PC, IR);
                PC = PC + 1;
            } while((IR >> 24) != HALT);

            PC = 0;

            while(!HALT) {
                IR = code2[PC];
                PC = PC + 1;
                exe(IR);
            }

            printf("Ninja Virtual Machine stopped\n");
            
        } else if(strcmp(argv[1],"--prog3") == 0){
            unsigned int IR = 0;
            int PC = 0;
            printf("Ninja Virtual Machine started\n");

            unsigned int code3[] = {
                (RDCHR << 24),
                (WRINT << 24),
                (PUSHC << 24) | IMMEDIATE('\n'),
                (WRCHR << 24),
                (HALT << 24)
            };

            do {
                IR = code3[PC];
                programlistner(PC, IR);
                PC = PC + 1;
            } while((IR >> 24) != HALT);

            PC = 0;

            while(!HALT) {
                IR = code3[PC];
                PC = PC + 1;
                exe(IR);
            }

            printf("Ninja Virtual Machine stopped\n");
            
        } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            printf("usage: %s [option] [option] ...\n", argv[0]);
            printf("\t\t--prog1           select program 1 to execute\n");
            printf("\t\t--prog2           select program 2 to execute\n");
            printf("\t\t--prog3           select program 3 to execute\n");
            printf("\t--version        show version and exit\n");
            printf("\t-h, --help       show this message and exit\n");
        } else if (strcmp(argv[1], "--version") == 0) {
            printf("Ninja Virtual Machine version 1 Compiled %s at %s\n",__DATE__,__TIME__);
        } else {
            printf("Ninja Virtual Machine: invalid option -- '%s'\n", argv[1]);
            printf("Try '%s --help' for more information.\n", argv[0]);
        }
    } else {
        printf("Error: no program selected\n");
    }
    return 0;
}
