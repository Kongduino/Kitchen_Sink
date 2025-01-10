# Kitchen_Sink

A C & Xojo library with various functions that could come in handy. Comes with C test code, and a Xojo test application.

## C API

### Binary Search

```c
void quickSortInt(int array[], int low, int high);
int iterativeBinarySearch(int arr[], int low, int high, int x);
int recursiveBinarySearch(int arr[], int low, int high, int x);
int minDistance(int dist[], bool sptSet[], int V);
void Dijkstra(int V, int graph[V][V], int src, int* dist);
```

### Compression

```c
void printArray(int arr[], int n);
void swapMinHNode(struct MinHNode **a, struct MinHNode **b);
void minHeapify(struct MinHeap *minHeap, int idx);
int checkSizeOne(struct MinHeap *minHeap);
struct MinHNode *extractMin(struct MinHeap *minHeap);
void insertMinHeap(struct MinHeap *minHeap, struct MinHNode *minHeapNode);
void buildMinHeap(struct MinHeap *minHeap);
int isLeaf(struct MinHNode *root);
struct MinHeap *createAndBuildMinHeap(char item[], int freq[], int size);
struct MinHNode *buildHuffmanTree(char item[], int freq[], int size);
void printHCodes(struct MinHNode *root, char arr[], int top);
```

### Dict

```c
Dictionary *create_dict(void);
int add_item_label(Dictionary *, char label[], void *);
int add_item_index(Dictionary *, int index, void *);
void *get_element_label(Dictionary *, char[]);
void *get_element_index(Dictionary *, int);
void destroy(Dictionary *);
```

### Hashes

```c
void fillRandom(unsigned char *buffer, unsigned int len);
void hexDump(unsigned char *buf, long len);
unsigned long djb2(unsigned char *str, int len);
unsigned long sdbm(unsigned char *str, int len);
unsigned long loselose(unsigned char *str, int len);
void MD5Init(MD5_CTX *);
void MD5Update(MD5_CTX *, unsigned char *, unsigned int);
void MD5Final(unsigned char *, MD5_CTX *);
static void MD5Transform(UINT4[4], unsigned char[64]);
static void Encode(unsigned char *, UINT4 *, unsigned int);
static void Decode(UINT4 *, unsigned char *, unsigned int);
```

### Maths

```c
void SieveOfEratosthenes(long n);
unsigned char isPrime(long n);
int basicGCD(int a, int b);
int basicLCM(int a, int b);
bool isLeapYear(int year);
double factorial(int n);
float haversine(float lat1, float lon1, float lat2, float lon2, bool metric);
float toRad(float x);
```

### Sort

```c
void bubbleSortInt(int array[], int size);
void bubbleSortDouble(double array[], int size);
void insertionSortInt(int array[], int size);
void insertionSortDouble(double array[], int size);
void mergeInt(int arr[], int p, int q, int r);
void mergeSortInt(int arr[], int l, int r);
void mergeDouble(double arr[], int p, int q, int r);
void mergeSortDouble(double arr[], int l, int r);
int qsPartitionInt(int array[], int low, int high);
void quickSortInt(int array[], int low, int high);
int qsPartitionDouble(double array[], int low, int high);
void quickSortDouble(double array[], int low, int high);
int getMaxInt(int array[], int n);
```

## Xojo Demo

```
% ./test_sink
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
00.|1b af 82 dc 86 1f dd 87 e1 bb 2f 2e fb f6 20 82 | |........../... .|
01.|69 68 03 64 41 50 ff 79 0b b5 af f6 c3 07 0e 64 | |ih.dAP.y.......d|
02.|38 3f 49 73 50 c1 51 df c4 f2 bf 25 23 0b 38 77 | |8?IsP.Q....%#.8w|
03.|9d 76 d3 13 cd a1 e5 a5 67 f8 62 80 99 f3 f8 4b | |.v......g.b....K|
04.|b8 b4 9c 09 91 7a be 26 a7 b5 c7 b9 ac 5e 80 e5 | |.....z.&.....^..|
05.|49 5e e2 c1 5b af 6f fa 63 19 99 34 09 f6 c2 dd | |I^..[.o.c..4....|
06.|dc be 59 22 f7 df 9b 3b a8 47 f7 b2 6e 91 8b 50 | |..Y"...;.G..n..P|
07.|a8 b1 18 0f 75 a9 8a 50 b5 94 bb e0 c4 2f 01 00 | |....u..P...../..|
   +------------------------------------------------+ +----------------+
djb2: 0xFFA1BC019686B7C2
sdbm: 0x74EEE863E93AA729
lose lose: 0x000042FD

764587 is prime
65536 is not prime

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
 • 40.653, 2.100, 3.600, 1.400, 40.642
After:
 • 1.400, 2.100, 3.600, 40.642, 40.653

Before Insertion sorting arr22:
 • 40.653, 2.100, 3.600, 1.400, 40.642
After:
 • 1.400, 2.100, 3.600, 40.642, 40.653

Before Quick sorting arr23:
 • 40.653, 2.100, 3.600, 1.400, 40.642
After:
 • 1.400, 2.100, 3.600, 40.642, 40.653

GCD(10, 15) = 5
LCM(10, 15) = 30
GCD(35, 10) = 5
LCM(35, 10) = 70
GCD(31, 2) = 1
LCM(31, 2) = 62
GCD(99, 12) = 3
LCM(99, 12) = 396


Graph:
        0    1    2    3    4    5    7    8    9
====================================================
 0 |    0    4    0    0    0    0    0    8    0 |
 1 |    4    0    8    0    0    0    0   11    0 |
 2 |    0    8    0    7    0    4    0    0    2 |
 3 |    0    0    7    0    9   14    0    0    0 |
 4 |    0    0    0    9    0   10    0    0    0 |
 5 |    0    0    4   14   10    0    2    0    0 |
 6 |    0    0    0    0    0    2    0    1    6 |
 7 |    8   11    0    0    0    0    1    0    7 |
 8 |    0    0    2    0    0    0    6    7    0 |
====================================================


Vertex 		Distance from source = 0
   0 			0
   1 			4
   2 			12
   3 			19
   4 			21
   5 			11
   6 			9
   7 			8
   8 			14

Vertex 		Distance from source = 3
   0 			19
   1 			15
   2 			7
   3 			0
   4 			9
   5 			11
   6 			13
   7 			14
   8 			9


 Char | Huffman code
------|-------------
  n   | 0000
  d   | 00010000
  g   | 000100010
  o   | 000100011
  o   | 0001001
  n   | 000101
  K   | 00011
  n   | 001
  i   | 01
  u   | 1
------|-------------

Compressing kitchen_sink.dylib

Decompressing kitchen_sink.flz

 Dictionaries
==============
My age is 28, and my name is Christian.
My age is 56, and my name is Bobby.
Christian's age at index 0 is 28
Bobby's age at index 0 is 56
No entry for label `salary`
Yeah, yeah, yeah, I know... Dictionaries exist in Xojo and Python...

Leap Years:
==============
Is 1900 a leap year: no
Is 1967 a leap year: no
Is 1954 a leap year: no
Is 1988 a leap year: yes
Is 2000 a leap year: yes
Is 2024 a leap year: yes

Leap Years:
==============
Fact(-1): error!
Fact(2): 2.000000
Fact(5): 120.000000
Fact(8): 40320.000000
Fact(11): 39916800.000000
Fact(14): 87178291200.000000
Fact(17): 355687428096000.000000
Fact(20): 2432902008176640000.000000
Fact(23): 25852016738884978212864.000000
Fact(26): 403291461126605650322784256.000000
Fact(29): 8841761993739700772720181510144.000000
Fact(32): 263130836933693517766352317727113216.000000
Fact(35): 10333147966386144222209170348167175077888.000000
Fact(38): 523022617466601037913697377988137380787257344.000000
Fact(41): 33452526613163802763987613764361857922667238129664.000000
Fact(44): 2658271574788448529134213028096241889243150262529425408.000000

HAVERSINE:
=============
distance between 22.400000, 113.900002 and 22.400000, 114.000000:
 • 10.28 km for normal people,
 • or for Muricans, 163.72 Boeing 787-9 airplanes (6.39 mi)

MD5 TEST:
Source:
		 This is a short 32-char message
MD5 Hash:
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
00.|4e fc 57 d3 68 b5 59 e9 d2 9a 4a 92 f7 79 04 1a | |N.W.h.Y...J..y..|
   +------------------------------------------------+ +----------------+

Source:
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
00.|1b af 82 dc 86 1f dd 87 e1 bb 2f 2e fb f6 20 82 | |........../... .|
01.|69 68 03 64 41 50 ff 79 0b b5 af f6 c3 07 0e 64 | |ih.dAP.y.......d|
02.|38 3f 49 73 50 c1 51 df c4 f2 bf 25 23 0b 38 77 | |8?IsP.Q....%#.8w|
03.|9d 76 d3 13 cd a1 e5 a5 67 f8 62 80 99 f3 f8 4b | |.v......g.b....K|
04.|b8 b4 9c 09 91 7a be 26 a7 b5 c7 b9 ac 5e 80 e5 | |.....z.&.....^..|
05.|49 5e e2 c1 5b af 6f fa 63 19 99 34 09 f6 c2 dd | |I^..[.o.c..4....|
06.|dc be 59 22 f7 df 9b 3b a8 47 f7 b2 6e 91 8b 50 | |..Y"...;.G..n..P|
07.|a8 b1 18 0f 75 a9 8a 50 b5 94 bb e0 c4 2f 01 00 | |....u..P...../..|
   +------------------------------------------------+ +----------------+
MD5 Hash:
   +------------------------------------------------+ +----------------+
   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |
   +------------------------------------------------+ +----------------+
00.|71 5a 4d a5 cf 2c db 0c 9e bd d5 3b f5 15 ce de | |qZM..,.....;....|
   +------------------------------------------------+ +----------------+
```

## Python Demo

```
% python3 ./test_sink.py
bubbleSortInt
[89, 12, 33, 23, 127, 24, 10, 40]
[10, 12, 23, 24, 33, 40, 89, 127]
insertionSortInt
[89, 12, 33, 23, 127, 24, 10, 40]
[10, 12, 23, 24, 33, 40, 89, 127]
mergeSortInt
[89, 12, 33, 23, 127, 24, 10, 40]
[10, 12, 23, 24, 33, 40, 89, 127]
quickSortInt
[89, 12, 33, 23, 127, 24, 10, 40]
[10, 12, 23, 24, 33, 40, 89, 127]

iterativeBinarySearch
 • Element 40 is present at index 5
 • Element 41 is not present in array!

recursiveBinarySearch
 • Element 40 is present at index 5
 • Element 41 is not present in array!

GCD(10, 15) = 5
GCD(35, 10) = 5
GCD(31, 2) = 1
GCD(99, 12) = 3


Graph:
        0    1    2    3    4    5    7    8    9
====================================================

 0 |    0    4    0    0    0    0    0    8    0 |
 1 |    4    0    8    0    0    0    0   11    0 |
 2 |    0    8    0    7    0    4    0    0    2 |
 3 |    0    0    7    0    9   14    0    0    0 |
 4 |    0    0    0    9    0   10    0    0    0 |
 5 |    0    0    4   14   10    0    2    0    0 |
 6 |    0    0    0    0    0    2    0    1    6 |
 7 |    8   11    0    0    0    0    1    0    7 |
 8 |    0    0    2    0    0    0    6    7    0 |
====================================================



Vertex 		Distance from source = {source}

   0 			0
   1 			4
   2 			12
   3 			19
   4 			21
   5 			11
   6 			9
   7 			8
   8 			14
```
