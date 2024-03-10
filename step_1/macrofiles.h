#ifndef MACROFILES_H
#define MACROFILES_H

#define HALT 0

#define PUSHC 1
#define ADD   2
#define SUB   3
#define MUL   4
#define DIV   5
#define MOD   6

#define RDINT 7
#define WRINT 8
#define RDCHR 9
#define WRCHR 10

#define IMMEDIATE(x) ((x) & 0x00FFFFFF)
#define SIGN_EXTEND(i) ((i) & 0x00800000 ? (i) | 0xFF000000 : (i))
#define CAPACITY 10000

void exe(unsigned IR);
void programlistner(int i, unsigned ir);
void push(int x);
int pop(void);

#endif