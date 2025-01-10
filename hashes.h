#ifndef __HASHES__H
#define __HASHES__H
#include <stdio.h>

void fillRandom(unsigned char *buffer, unsigned int len);
void hexDump(unsigned char *buf, long len);
unsigned long djb2(unsigned char *str, int len);
unsigned long sdbm(unsigned char *str, int len);
unsigned long loselose(unsigned char *str, int len);
#endif
