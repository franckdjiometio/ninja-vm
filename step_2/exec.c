#include <stdio.h>
#include <stdlib.h>
#include "macrofiles.h"

void exe(unsigned IR)
{
     int rint = 0;
     char rchr;
     int a, b;

     switch (IR >> 24)
     {
     case HALT:
          printf("%d\n", pop());
          printf("Ninja Virtual Machine stopped\n");
          exit(0);
          break;

     case PUSHC:
          if (IR > 30000000)
          {
               push(SIGN_EXTEND(IR));
          }
          else
          {
               push(IMMEDIATE(IR));
          }
          break;

     case ADD:
          a = pop();
          b = pop();
          push(a + b);
          // printf("a:%d + b:%d\n",a,b);
          break;

     case SUB:
          a = pop();
          b = pop();
          push(b - a);
          break;

     case MUL:
          a = pop();
          b = pop();
          push(a * b);
          // printf("a:%d * b:%d\n",a,b);
          break;

     case DIV:
          a = pop();
          b = pop();
          if (a == 0)
          {
               printf("Division by 0 is not possible");
          }
          else
          {
               push(b / a);
          }
          break;

     case MOD:
          a = pop();
          b = pop();
          push(b % a);
          break;

     case WRINT:
          break;

     case RDINT:
          scanf("%d", &rint);
          push(rint);
          break;

     case WRCHR:
          printf("%c", pop());
          break;

     case RDCHR:
          scanf("%c", &rchr);
          push(rchr);
          break;

     case PUSHG:
          pushg(IMMEDIATE(IR));
          break;

     case POPG:
          popg(IMMEDIATE(IR));
          break;

     case ASF:
          asf(IMMEDIATE(IR));
          break;

     case RSF: // printf("%d \n",pop());
          rsf();
          break;

     case PUSHL:
          pushl(IMMEDIATE(IR));
          break;

     case POPL:
          popl(IMMEDIATE(IR));
          // printf("popl %d \n",a);
          break;
     }
}