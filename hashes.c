#include "hashes.h"

// Fills a buffer with random bytes from /dev/random
void fillRandom(unsigned char *buffer, unsigned int len) {
  FILE *fp = fopen ("/dev/random", "r");
  fgets((char*)buffer, len, fp);
  fclose(fp);
}

void hexDump(unsigned char *buf, long len) {
  char alphabet[17] = "0123456789abcdef";
  printf("   +------------------------------------------------+ +----------------+\n");
  printf("   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |\n");
  for (long i = 0; i < len; i += 16) {
    if (i % 128 == 0)
      printf("   +------------------------------------------------+ +----------------+\n");
    char s[] = "|                                                | |                |\n";
    unsigned char ix = 1, iy = 52;
    for (int j = 0; j < 16; j++) {
      if (i + j < len) {
        unsigned char c = buf[i + j];
        s[ix++] = alphabet[(c >> 4) & 0x0F];
        s[ix++] = alphabet[c & 0x0F];
        ix++;
        if (c > 31 && c < 128)
          s[iy++] = c;
        else
          s[iy++] = '.';
      }
    }
    unsigned char index = i / 16;
    printf("%02x.%s", index, s);
  }
  printf("   +------------------------------------------------+ +----------------+\n");
}

unsigned long djb2(unsigned char *str, int len) {
  unsigned long hash = 0x1505;
  unsigned char c;
  int i;
  for (i = 0; i < len; i++) {
    c = str[i];
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
  return hash;
}

unsigned long sdbm(unsigned char *str, int len) {
  unsigned long hash = 0;
  unsigned char c;
  int i;
  for (i = 0; i < len; i++) {
    c = str[i];
    hash = c + (hash << 6) + (hash << 16) - hash;
  }
  return hash;
}

unsigned long loselose(unsigned char *str, int len) {
  unsigned long hash = 0;
  int i;
  for (i = 0; i < len; i++) {
    hash += str[i];
  }
  return hash;
}

