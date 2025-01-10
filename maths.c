#include "maths.h"

// C program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
void SieveOfEratosthenes(long n) {
  // Create a boolean array "prime[0..n]" and initialize
  // all entries it as true. A value in prime[i] will
  // finally be false if i is Not a prime, else true.
  unsigned char *prime;
  prime = malloc(n + 1);
  memset(prime, 1, n + 1);
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
  prime = malloc(n + 1);
  memset(prime, 1, n + 1);
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

// https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
// Function to return gcd of a and b
int basicGCD(int a, int b) {
  if (a == 0)
    return b;
  return basicGCD(b % a, a);
}

int basicLCM(int a, int b) {
  return (a * b) / basicGCD(a, b);
}

bool isLeapYear(int year) {
  // leap year if perfectly divisible by 400
  if (year % 400 == 0) return true;
  // not a leap year if divisible by 100
  // but not divisible by 400
  else if (year % 100 == 0) return false;
  // leap year if not divisible by 100
  // but divisible by 4
  else if (year % 4 == 0) return true;
  // all other years are not leap years
  else return false;
}

double factorial(int n) {
  if (n < 3) return n;
  double fact = 2, i;
  for (i = 3; i <= n; ++i)
    fact *= i;
  return fact;
}

float toRad(float x) {
  return x * 3.141592653 / 180;
}

float haversine(float lat1, float lon1, float lat2, float lon2, bool metric) {
  float R;
  if (metric) R = 6371; // km
  else R = 3958.756; // mi
  float x1 = lat2 - lat1;
  float dLat = toRad(x1);
  float x2 = lon2 - lon1;
  float dLon = toRad(x2);
  float a =
    sin(dLat / 2) * sin(dLat / 2) +
    cos(toRad(lat1)) * cos(toRad(lat2)) *
    sin(dLon / 2) * sin(dLon / 2);
  float c = 2 * atan2(sqrt(a), sqrt(1 - a));
  float d = R * c;
  return round(d * 100.0) / 100;
}
