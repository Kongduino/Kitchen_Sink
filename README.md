# Kitchen_Sink

A C & Xojo library with various functions that could come in handy. Comes with C test code, and a Xojo test application.

### C API

```c
void hexDump(unsigned char *buf, long len);
```
Self-explanatory

```c
unsigned long djb2(unsigned char *str, int len);
```
djb2 hash.

```c
unsigned long sdbm(unsigned char *str, int len);
```
sdbm hash.

```c
unsigned long loselose(unsigned char *str, int len);
```
lose lose hash.

```c
void fillRandom(unsigned char *buffer, unsigned int len);
```
Fills a buffer with random numbers from `/dev/random`.

```c
void SieveOfEratosthenes(long n);
```
Sieve of Eratosthenes.

```c
unsigned char isPrime(long n);
```
Uses a sieve of Eratosthenes to determine whether a number is a prime.

```c
int iterativeBinarySearch(int arr[], int low, int high, int x);
```
Iterative Binary Search.

```c
int recursiveBinarySearch(int arr[], int low, int high, int x);
```
Recursive Binary Search.

```c
void bubbleSortInt(int array[], int size);
```
BubbleSort for integers.

```c
void bubbleSortDouble(double array[], int size);
```
BubbleSort for doubles.

```c
void insertionSortInt(int array[], int size);
```
InsertionSort for integers.

```c
void insertionSortDouble(double array[], int size);
```
InsertionSort for doubles.

```c
void mergeSortInt(int arr[], int l, int r);
```
MergeSort for integers.

```c
void mergeSortDouble(double arr[], int l, int r);
```
MergeSort for doubles.

```c
void quickSortInt(int array[], int low, int high);
```
QuickSort for integers.

```c
void quickSortDouble(double array[], int low, int high);
```
QuickSort for doubles.




```
% make
gcc -Wall -O3 -g -c *.c
gcc *.o -o test_sink
./test_sink
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
00.|13 73 55 77 65 06 43 bd 68 39 05 7f 76 33 29 c2 | |.sUwe.C.h9.v3).|
01.|f0 9c 72 74 2a c7 da a8 e9 51 77 4d 58 3d de 5c | |..rt*....QwMX=.\|
02.|cf 73 f0 06 60 03 7d e2 a4 77 4f 1b f3 b0 2d c1 | |.s..`.}..wO...-.|
03.|6b 9d 45 90 bc 38 24 63 b3 2c 2f 58 85 ef 9c b6 | |k.E..8$c.,/X....|
04.|4e b9 c2 c8 37 e7 fe 1c c8 dd 08 01 9d 8b 44 cf | |N...7.........D.|
05.|7b 82 80 1e cc 5f 7b 56 e9 e2 c3 55 e3 fc 54 07 | |{...._{V...U..T.|
06.|54 15 b3 d2 b5 ae 9c 26 a2 cb e5 80 41 20 dd ba | |T......&....A ..|
07.|27 05 dc 1e 52 f4 89 38 d4 90 e1 64 43 2e 8b 00 | |'...R..8...dC...|
   +------------------------------------------------+ +----------------+
djb2: 0x82D638BB938E1D36
sdbm: 0xF881FADAA059DCEB
lose lose: 0x00003ED1

764587 is prime

iterativeBinarySearch
 • Element 10 is present at index 3
 • Element 41 is not present in array!

recursiveBinarySearch
 • Element 90 is not present in array!
 • Element 40 is present at index 7

Before Bubble sorting arr1:
 • 89, 12, 33, 23, 127, 24, 10, 40
After:
 • 10, 12, 23, 24, 33, 40, 89, 127

Before Insertion sorting arr11:
 • 89, 12, 33, 23, 127, 24, 10, 40
After:
 • 10, 12, 23, 24, 33, 40, 89, 127

Before Merge sorting arr12:
 • 89, 12, 33, 23, 127, 24, 10, 40
After:
 • 10, 12, 23, 24, 33, 40, 89, 127

Before Bubble sorting arr2:
 • 2.100, 3.600, 1.400, 40.653, 40.642
After:
 • 1.400, 2.100, 3.600, 40.642, 40.653

Before Insertion sorting arr22:
 • 40.653, 2.100, 3.600, 1.400, 40.642
After:
 • 1.400, 2.100, 3.600, 40.642, 40.653

Before Quick sorting arr23:
 • 40.567, 2.120, 3.230, 1.340, 40.456
After:
 • 1.340, 2.120, 3.230, 40.456, 40.567

gcc -dynamic binary_search.o hashes.o sieve.o sort.o test.o -o kitchen_sink.dylib
% 
```

### Xojo API

```
Sub HexDump(mb As MemoryBlock)
```
Self-explanatory
```
Function djb2_hash(mb As MemoryBlock) As UInt32
```
djb2 hash, from the library.
```
Function djb2_native(mb As MemoryBlock) As UInt32
```
djb2 hash, in Xojo.
```
Function sdbm_hash(mb As MemoryBlock) As UInt32
```
sdbm hash, from the library.
```
Function sdbm_native(mb As MemoryBlock) As UInt32
```
sdbm hash, in Xojo.
```
Function loselose_hash(mb As MemoryBlock) As UInt32
```
lose lose hash, from the library.
```
Function loselose_native(mb As MemoryBlock) As UInt32
```
lose lose hash, in Xojo.
```
Sub FillRandomBuffer(buffer As MemoryBlock, len As Integer)
```
Fills a buffer with random numbers from `/dev/random`.
```
Function IsPrime(n As UInt64) As Boolean
```
Uses a sieve of Eratosthenes to determine whether a number is a prime.
```
Function iterBinSearch(arr() As Integer, x As Integer) As Integer
```
Iterative Binary Search.
```
Function recursiveBinSearch(arr() As Integer, x As Integer) As Integer
```
Recursive Binary Search.

```
Function BubbleSort(arr() As Integer / Double) As Integer / Double()
```
BubbleSort
```
Function InsertionSort(arr() As Integer / Double) As Integer / Double()
```
Insertion Sort
```
Function MergeSort(arr() As Integer / Double) As Integer / Double()
```
MergeSort
```
Function QuickSort(arr() As Integer / Double) As Integer / Double()
```
QuickSort
