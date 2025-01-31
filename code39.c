#include "code39.h"

int c39GetSize(int ln) {
  return ((ln+1) * 10 + 9) * 1.5;
}

int lookupChar(char c) {
  char x = c;
  if (x>='a' && x<='z')
    x -= 32;
  for(int i = 0; i < 44; i++) {
    if (x == C39_Alphabet[i]) return i;
  }
  return -1;
}

int createCode39(char *myText, int ln, char *buffer) {
  printf("mytext:\n");
  hexDump((unsigned char *)myText, ln);
  printf("buffer:\n");
  hexDump((unsigned char *)buffer, sizeof(buffer));
  // buffer should be (ln+1) * 10 + 9, see get c39GetSize()
  int i, j, k, n, ps, px = 0, colorIndex;
  char c = '*';
  ps = lookupChar(c);
    if (ps == -1) {
      printf("lookupChar(%d) returned -1!\n", c);
      return -1;
    }
  colorIndex = 0;
  for (j = 0; j < 9; j++) {
    k = C39_Codes[ps][j] - 0x30;
    for(n = 0; n < k; n++) {
      buffer[px++] = C39_Colors[colorIndex];
    }
    colorIndex = 1 - colorIndex;
  }
  buffer[px++] = ' '; // spacing
  for(i = 0; i < ln; i++) {
    c = myText[i];
    ps = lookupChar(c);
    if (ps == -1) {
      printf("lookupChar(%d) returned -1!\n", c);
      return -2;
    }
    colorIndex = 0;
    for (j = 0; j < 9; j++) {
      k = C39_Codes[ps][j] - 0x30;
      for(n = 0; n < k; n++) {
        buffer[px++] = C39_Colors[colorIndex];
      }
      colorIndex = 1 - colorIndex;
    }
    buffer[px++] = ' '; // spacing
  }
  c = '*';
  ps = lookupChar(c);
    if (ps == -1) {
      printf("lookupChar(%d) returned -1!\n", c);
      return -3;
    }
  colorIndex = 0;
  for (j = 0; j < 9; j++) {
    k = C39_Codes[ps][j] - 0x30;
    for(n = 0; n < k; n++) {
      buffer[px++] = C39_Colors[colorIndex];
    }
    colorIndex = 1 - colorIndex;
  }
  hexDump((unsigned char *)buffer, px);
  return px;
}