#include <stdio.h>
#include "macrofiles.h"

void programlistner(int i, unsigned ir)
{

     printf("%03d:\t", i);

     switch (ir >> 24)
     {
     case HALT:
          printf("halt\t\n");

          break;
     case PUSHC:
          printf("pushc\t");
          if (ir > 30000000)
          {
               printf("%d", SIGN_EXTEND(ir));
          }
          else
          {
               printf("%d", IMMEDIATE(ir));
          }
          printf("\n");

          break;
     case ADD:
          printf("add\t\n");
          break;

     case SUB:
          printf("sub\t\n");
          break;
     case MUL:
          printf("mul\t\n");

          break;
     case DIV:
          printf("div\t\n");
          break;
     case MOD:
          printf("mod\t\n");
          break;
     case WRINT:
          printf("wrint\t\n");
          break;
     case RDINT:
          printf("rdint\t\n");
          break;
     case WRCHR:
          printf("wrchr\t\n");
          break;
     case RDCHR:
          printf("rdchr\t\n");
          break;
     case PUSHG:
          printf("pushg\t%d\n", IMMEDIATE(ir));
          break;

     case POPG:
          printf("popg\t%d\n", IMMEDIATE(ir));
          break;

     case ASF:
          printf("asf\t%d\n", IMMEDIATE(ir));
          break;

     case RSF:
          printf("rsf\t\n");
          break;

     case PUSHL:
          printf("pushl\t%d\n", IMMEDIATE(ir));
          break;

     case POPL:
          printf("popl\t%d\n", IMMEDIATE(ir));
          break;
     }
}