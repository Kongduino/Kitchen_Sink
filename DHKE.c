#include "hashes.h"
#include "BASE64.h"

uint64_t P = 0xffffffffffffffc5;
uint64_t G = 5;

// Power function to return value of a ^ b mod P
uint64_t power(uint64_t a, uint64_t b) {
  if (b == 1) return a;
  uint64_t t = power(a, b / 2);
  if (b % 2 == 0) return (t * t) % P;
  else return (((t * t) % P) * a) % P;
}

uint64_t randomint64() {
  uint64_t a = 0;
  uint8_t j;
  unsigned char buffer[8];
  fillRandom(buffer, 8);
  for (j = 0; j < 8; j++) {
    uint8_t x = buffer[j];
    a = (a << 8) | x;
  }
  return a;
}

void *fourTo32(uint64_t*what, uint8_t myKey[32]) {
  *(uint64_t*)myKey = what[3];
  memcpy(myKey + 24, myKey, 8);
  *(uint64_t*)myKey = what[2];
  memcpy(myKey + 16, myKey, 8);
  *(uint64_t*)myKey = what[1];
  memcpy(myKey + 8, myKey, 8);
  *(uint64_t*)myKey = what[0];
}

void array2B64(uint8_t *src, uint8_t *dst, size_t *olen) {
  memset(dst, 0, 64); // Belt & suspenders
  uint8_t rslt = base64_encode(src, 32, dst);
}

void b642Array(uint8_t *src, uint8_t *dst, size_t *olen, size_t slen) {
  memset(dst, 0, 32); // Belt & suspenders
  uint8_t rslt = base64_decode((const unsigned char *)src, slen, dst);
}

void array2uint64_t(uint8_t src[32], uint64_t BobPublic[4]) {
  uint8_t i, j, n = 0;
  for (i = 0; i < 32; i += 8) {
    uint64_t a = 0;
    for (j = 0; j < 8; j++) {
      uint8_t x = src[i];
      a = (a << 8) | x;
    }
    BobPublic[n++] = a;
  }
}

void fourUint64_t2Array(uint64_t BobPublic[4], uint8_t dst[32]) {
  uint8_t i, j;
  for (i = 0; i < 4; i ++) {
    uint64_t a = BobPublic[i];
    for (j = 0; j < 8; j++) {
      dst[(i * 8) + (7 - j)] = a & 0xff;
      a = a >> 8;
    }
  }
}
