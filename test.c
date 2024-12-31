#include <stdio.h>
#include <stdbool.h>  // For boolean data type (bool, true, false)

void hexDump(unsigned char *buf, long len);
unsigned long djb2(unsigned char *str, int len);
unsigned long sdbm(unsigned char *str, int len);
unsigned long loselose(unsigned char *str, int len);
void fillRandom(unsigned char *buffer, unsigned int len);
unsigned char isPrime(long n);
void SieveOfEratosthenes(long n);
int iterativeBinarySearch(int arr[], int low, int high, int x);
int recursiveBinarySearch(int arr[], int low, int high, int x);
void bubbleSortInt(int array[], int size);
void bubbleSortDouble(double array[], int size);
void insertionSortInt(int array[], int size);
void insertionSortDouble(double array[], int size);
void mergeSortInt(int arr[], int l, int r);
void mergeSortDouble(double arr[], int l, int r);
void quickSortInt(int array[], int low, int high);
void quickSortDouble(double array[], int low, int high);
int basicGCD(int a, int b);
void Dijkstra(int V, int graph[V][V], int src, int *dist);

int main(int argc, char **argv) {
  unsigned int len = 128;
  unsigned char buffer[len];
  fillRandom(buffer, len);
  hexDump(buffer, len);

  unsigned long hash = djb2(buffer, len);
  printf("djb2: 0x%08lX\n", hash);

  hash = sdbm(buffer, len);
  printf("sdbm: 0x%08lX\n", hash);

  hash = loselose(buffer, len);
  printf("lose lose: 0x%08lX\n", hash);

  unsigned char rslt = isPrime(764587);
  printf("\n%ld is %s\n", 764587l, rslt == 1 ? "prime" : "not prime");

  printf("\niterativeBinarySearch\n");
  int arr0[] = { 2, 3, 4, 10, 40 };
  int n = sizeof(arr0) / sizeof(arr0[0]);
  int query = 10;
  int result = iterativeBinarySearch(arr0, 0, n - 1, query);
  if (result == -1) printf(" • Element %d is not present in array!\n", query);
  else printf(" • Element %d is present at index %d\n", query, result);
  query = 41;
  result = iterativeBinarySearch(arr0, 0, n - 1, query);
  if (result == -1) printf(" • Element %d is not present in array!\n", query);
  else printf(" • Element %d is present at index %d\n", query, result);

  printf("\nrecursiveBinarySearch\n");
  int arr1[] = { 89, 12, 33, 23, 127, 24, 10, 40 };
  n = sizeof(arr1) / sizeof(arr1[0]);
  query = 90;
  result = recursiveBinarySearch(arr1, 0, n - 1, query);
  if (result == -1) printf(" • Element %d is not present in array!\n", query);
  else printf(" • Element %d is present at index %d\n", query, result);
  query = 40;
  result = recursiveBinarySearch(arr1, 0, n - 1, query);
  if (result == -1) printf(" • Element %d is not present in array!\n", query);
  else printf(" • Element %d is present at index %d\n", query, result);

  printf("\nBefore Bubble sorting arr1:\n");
  printf(" • %d", arr1[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %d", arr1[ix]);
  }
  printf("\nAfter:\n");
  bubbleSortInt(arr1, n);
  printf(" • %d", arr1[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %d", arr1[ix]);
  }
  printf("\n");

  int arr11[] = { 89, 12, 33, 23, 127, 24, 10, 40 };
  printf("\nBefore Insertion sorting arr11:\n");
  printf(" • %d", arr11[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %d", arr11[ix]);
  }
  printf("\nAfter:\n");
  insertionSortInt(arr11, n);
  printf(" • %d", arr11[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %d", arr11[ix]);
  }
  printf("\n");

  int arr12[] = { 89, 12, 33, 23, 127, 24, 10, 40 };
  printf("\nBefore Merge sorting arr12:\n");
  printf(" • %d", arr12[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %d", arr12[ix]);
  }
  printf("\nAfter:\n");
  mergeSortInt(arr12, 0, n - 1);
  printf(" • %d", arr12[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %d", arr12[ix]);
  }
  printf("\n");

  double arr2[] = { 2.1, 3.6, 1.4, 40.653, 40.642 };
  n = sizeof(arr2) / sizeof(arr2[0]);

  printf("\nBefore Bubble sorting arr2:\n");
  printf(" • %.3f", arr2[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %.3f", arr2[ix]);
  }
  printf("\nAfter:\n");
  bubbleSortDouble(arr2, n);
  printf(" • %.3f", arr2[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %.3f", arr2[ix]);
  }
  printf("\n");

  double arr22[] = { 40.653, 2.1, 3.6, 1.4, 40.642 };
  n = sizeof(arr22) / sizeof(arr22[0]);

  printf("\nBefore Insertion sorting arr22:\n");
  printf(" • %.3f", arr22[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %.3f", arr22[ix]);
  }
  printf("\nAfter:\n");
  insertionSortDouble(arr22, n);
  printf(" • %.3f", arr22[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %.3f", arr22[ix]);
  }
  printf("\n");

  double arr23[] = { 40.567, 2.12, 3.23, 1.34, 40.456 };
  n = sizeof(arr23) / sizeof(arr23[0]);

  printf("\nBefore Quick sorting arr23:\n");
  printf(" • %.3lf", arr23[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %.3lf", arr23[ix]);
  }
  printf("\nAfter:\n");
  quickSortDouble(arr23, 0, n - 1);
  printf(" • %.3lf", arr23[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %.3lf", arr23[ix]);
  }
  printf("\n");

  int a = 10, b = 15;
  printf("GCD(%d, %d) = %d\n", a, b, basicGCD(a, b));
  a = 35, b = 10;
  printf("GCD(%d, %d) = %d\n", a, b, basicGCD(a, b));
  a = 31, b = 2;
  printf("GCD(%d, %d) = %d\n", a, b, basicGCD(a, b));
  a = 99, b = 12;
  printf("GCD(%d, %d) = %d\n", a, b, basicGCD(a, b));

/* Let us create an example graph
 https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
 */
// Number of vertices in the graph
#define myV 9
  int graph[myV][myV] = {
    { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
  };
  printf("\n\nGraph:\n        0    1    2    3    4    5    7    8    9\n====================================================\n");
  for (b = 0; b < myV; b++) {
    printf(" %d |", b);
    for (a = 0; a < myV; a++) {
      printf("% 5d", graph[a][b]);
    }
    printf(" |\n");
  }
  printf("====================================================\n\n");
  // Function call
  int dist[myV], source = 0;
  Dijkstra(myV, graph, source, dist);
  printf("\nVertex \t\tDistance from source = %d\n", source);
  for (int i = 0; i < myV; i++)
    printf("   %d \t\t\t%d\n", i, dist[i]);
  source = 3;
  Dijkstra(myV, graph, source, dist);
  printf("\nVertex \t\tDistance from source = %d\n", source);
  for (int i = 0; i < myV; i++)
    printf("   %d \t\t\t%d\n", i, dist[i]);
  printf("\n\n\n\n");
  return 0;
}
