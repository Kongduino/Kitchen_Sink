#ifndef __MATHS__H
#define __MATHS__H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>  // For boolean data type (bool, true, false)
#include <math.h> /* sin */

void SieveOfEratosthenes(long n);
unsigned char isPrime(long n);
int basicGCD(int a, int b);
int basicLCM(int a, int b);
bool isLeapYear(int year);
double factorial(int n);
float haversine(float lat1, float lon1, float lat2, float lon2, bool metric);
float toRad(float x);
#endif
