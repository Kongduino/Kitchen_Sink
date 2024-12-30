#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// C program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
void SieveOfEratosthenes(long n) {
  // Create a boolean array "prime[0..n]" and initialize
  // all entries it as true. A value in prime[i] will
  // finally be false if i is Not a prime, else true.
  unsigned char *prime;
  prime = malloc(n+1);
  memset(prime, 1, n+1);
  for (long p = 2; p * p <= n; p++) {
    // If prime[p] is not changed, then it is a prime
    if (prime[p] == 1) {
      // Update all multiples of p greater than or
      // equal to the square of it numbers which are
      // multiple of p and are less than p^2 are
      // already been marked.
      for (int i = p * p; i <= n; i += p)
        prime[i] = 0;
    }
  }
  // Print all prime numbers
  for (long p = 2; p <= n; p++)
    if (prime[p] == 1)
      printf("%ld ", p);
  printf("\n\n");
}

unsigned char isPrime(long n) {
  unsigned char *prime;
  prime = malloc(n+1);
  memset(prime, 1, n+1);
  for (long p = 2; p * p <= n; p++) {
    // If prime[p] is not changed, then it is a prime
    if (prime[p] == 1) {
      // Update all multiples of p greater than or
      // equal to the square of it numbers which are
      // multiple of p and are less than p^2 are
      // already been marked.
      for (int i = p * p; i <= n; i += p)
        prime[i] = 0;
    }
  }
  unsigned char x = prime[n];
  free(prime);
  return x;
}
