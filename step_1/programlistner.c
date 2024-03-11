#include <stdio.h>
#include "macrofiles.h"

void programlistner(int i, unsigned ir)
{
     if (i >= 0 && i < 10)
     {
          printf("00%d:    ", i);
     }
     if (i > 9 && i < 100)
     {
          printf("0%d:    ", i);
     }
     if (i > 99 && i < 1000)
     {
          printf("%d:    ", i);
     }

     switch (ir >> 24)
     {
     case HALT:
          printf("halt\n");
          break;
     case PUSHC:
          printf("pushc   ");
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
          printf("add   \n");
          break;
     case SUB:
          printf("sub   \n");
          break;
     case MUL:
          printf("mul   \n");
          break;
     case DIV:
          printf("div   \n");
          break;
     case MOD:
          printf("mod   \n");
          break;
     case WRINT:
          printf("wrint   \n");
          break;
     case RDINT:
          printf("rdint   \n");
          break;
     case WRCHR:
          printf("wrchr   \n");
          break;
     case RDCHR:
          printf("rdchr   \n");
          break;
     }
}
