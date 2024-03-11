#include <stdio.h>
#include <stdlib.h>
#include "macrofiles.h"

void push(int x)
{
    if (sp == CAPACITY - 1)
        return;
    else
    {
        stack[sp++] = x;
    }
}

void pushg(int x)
{
    push(sda[x]);
    // printf("pushg :%d ",sda[x]);
}

void pushl(int x)
{
    if (fp == sp)
        return;
    else
    {
        push(stack[fp + x]);
    }
}

int pop(void)
{

    if (sp == 0)
    {
        return 0;
    }
    else
        return stack[--sp];
}

int popg(int x)
{
    return sda[x] = pop();
}

int popl(int x)
{
    return stack[fp + x] = pop();
}

void asf(int x)
{
    push(fp);
    fp = sp;
    sp = sp + x;
}

void rsf()
{
    int tmp = pop();
    sp = fp;
    fp = pop();
    push(tmp);
}
