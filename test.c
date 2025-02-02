#include "test.h"

void printIntArray(int *arr, int n) {
  printf(" • %d", arr[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %d", arr[ix]);
  }
}

void printDoubleArray(double *arr, int n) {
  printf(" • %.3f", arr[0]);
  for (int ix = 1; ix < n; ix++) {
    printf(", %.3f", arr[ix]);
  }
}

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

  unsigned char rslt = isPrime(764587l);
  printf("\n%ld is %s\n", 764587l, rslt == 1 ? "prime" : "not prime");
  rslt = isPrime(65536l);
  printf("%ld is %s\n", 65536l, rslt == 1 ? "prime" : "not prime");

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
  printIntArray(arr1, n);
  bubbleSortInt(arr1, n);
  printf("\nAfter:\n");
  printIntArray(arr1, n);
  printf("\n");

  int arr11[] = { 89, 12, 33, 23, 127, 24, 10, 40 };
  printf("\nBefore Insertion sorting arr11:\n");
  printIntArray(arr11, n);
  insertionSortInt(arr11, n);
  printf("\nAfter:\n");
  printIntArray(arr11, n);
  printf("\n");

  int arr12[] = { 89, 12, 33, 23, 127, 24, 10, 40 };
  printf("\nBefore Merge sorting arr12:\n");
  printIntArray(arr12, n);
  mergeSortInt(arr12, 0, n - 1);
  printf("\nAfter:\n");
  printIntArray(arr12, n);
  printf("\n");

  double arr2[] = { 40.653, 2.1, 3.6, 1.4, 40.642 };
  n = sizeof(arr2) / sizeof(arr2[0]);
  printf("\nBefore Bubble sorting arr2:\n");
  printDoubleArray(arr2, n);
  bubbleSortDouble(arr2, n);
  printf("\nAfter:\n");
  printDoubleArray(arr2, n);
  printf("\n");

  double arr22[] = { 40.653, 2.1, 3.6, 1.4, 40.642 };
  printf("\nBefore Insertion sorting arr22:\n");
  printDoubleArray(arr22, n);
  insertionSortDouble(arr22, n);
  printf("\nAfter:\n");
  printDoubleArray(arr22, n);
  printf("\n");

  double arr23[] = { 40.653, 2.1, 3.6, 1.4, 40.642 };
  printf("\nBefore Quick sorting arr23:\n");
  printDoubleArray(arr23, n);
  quickSortDouble(arr23, 0, n - 1);
  printf("\nAfter:\n");
  printDoubleArray(arr23, n);
  printf("\n");

  int a = 10, b = 15;
  printf("\nGCD(%d, %d) = %d\n", a, b, basicGCD(a, b));
  printf("LCM(%d, %d) = %d\n", a, b, basicLCM(a, b));
  a = 35, b = 10;
  printf("GCD(%d, %d) = %d\n", a, b, basicGCD(a, b));
  printf("LCM(%d, %d) = %d\n", a, b, basicLCM(a, b));
  a = 31, b = 2;
  printf("GCD(%d, %d) = %d\n", a, b, basicGCD(a, b));
  printf("LCM(%d, %d) = %d\n", a, b, basicLCM(a, b));
  a = 99, b = 12;
  printf("GCD(%d, %d) = %d\n", a, b, basicGCD(a, b));
  printf("LCM(%d, %d) = %d\n", a, b, basicLCM(a, b));

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

  char arr[] = "Konngduino";
  int freq[] = { 5, 1, 6, 3 };
  int size = sizeof(arr) / sizeof(arr[0]) - 1;
  printf("\n\n Char | Huffman code\n------|-------------\n");
  struct MinHNode *root = buildHuffmanTree(arr, freq, size);
  int top = 0;
  printHCodes(root, arr, top);
  printf("------|-------------\n");

  printf("\nCompressing kitchen_sink.dylib\n");
  flzCompress("/tmp/kitchen_sink.dylib", "/tmp/kitchen_sink.flz");
  printf("\nDecompressing kitchen_sink.flz\n");
  flzDecompress("/tmp/kitchen_sink.flz", "/tmp/kitchen_sink.so");

  // https://github.com/TheAlgorithms/C/
  printf("\n Dictionaries\n==============\n");
  Dictionary *testObj1;
  Dictionary *testObj2;
  int value1 = 28;
  int value2 = 56;
  testObj1 = create_dict();
  testObj2 = create_dict();
  add_item_label(testObj1, "age", &value1);
  add_item_label(testObj1, "name", "Christian");
  add_item_label(testObj2, "age", &value2);
  add_item_label(testObj2, "name", "Bobby");
  /*
        test for function add_item_label
        attention:
        The void* pointer must be converted into an int* pointer.
        After that you can dereference it.
    */
  printf(
    "My age is %d, and my name is %s.\n",
    *((int *)get_element_label(testObj1, "age")),
    (char *)get_element_label(testObj1, "name"));
  printf(
    "My age is %d, and my name is %s.\n",
    *((int *)get_element_label(testObj2, "age")),
    (char *)get_element_label(testObj2, "name"));
  /* test for function add_item_index */
  if (!add_item_index(testObj1, 0, &value1)) {
    printf(
      "%s's age at index %d is %d\n",
      (char *)get_element_label(testObj1, "name"),
      0,
      *((int *)get_element_index(testObj1, 0)));
  }
  if (!add_item_index(testObj2, 0, &value2)) {
    printf(
      "%s's age at index %d is %d\n",
      (char *)get_element_label(testObj2, "name"),
      0,
      *((int *)get_element_index(testObj2, 0)));
  }
  /* error scenario */
  if (get_element_label(testObj2, "salary") == NULL) {
    printf("No entry for label `salary`\n");
  } else {
    printf(
      "%s's salary is %d.\n",
      (char *)get_element_label(testObj2, "name"),
      *((int *)get_element_label(testObj2, "salary")));
  }
  /* tidy up */
  destroy(testObj1);
  destroy(testObj2);
  printf("Yeah, yeah, yeah, I know... Dictionaries exist in Xojo and Python...\n");

  printf("\nLeap Years:\n==============\n");
  int years[] = { 1900, 1967, 1954, 1988, 2000, 2024 };
  for (int i = 0; i < 6; i++) {
    printf("Is %d a leap year: %s\n", years[i], isLeapYear(years[i]) ? "yes" : "no");
  }

  printf("\nLeap Years:\n==============\n");
  for (int i = -1; i < 45; i += 3) {
    double r = factorial(i);
    printf("Fact(%d): ", i);
    if (r <= 0) printf("error!\n");
    else printf("%lf\n", r);
  }

  float lat0, lat1, long0, long1;
  printf("\nHAVERSINE:\n=============\n");
  lat0 = 22.4;
  lat1 = 22.4;
  long0 = 113.9;
  long1 = 114.0;
  float km = haversine(lat0, long0, lat1, long1, true);
  float mi = haversine(lat0, long0, lat1, long1, false);
  int x = buffer[0] % numUSMeasures;
  printf("distance between %.6f, %.6f and %.6f, %.6f:\n • %.2f km for normal people,\n"
    " • or for Muricans, %.2f %s (%.2f mi)\n", lat0, long0, lat1, long1, km, (km / USMeasures[x].value), USMeasures[x].name, mi);

  printf("\nMD5 TEST:\nSource:\n\t\t This is a short 32-char message\nMD5 Hash:\n");
  MD5_CTX ctx;
  unsigned char input[] = "This is a short 32-char message";
  unsigned char digest[16];
  MD5Init(&ctx);
  MD5Update(&ctx, input, 32);
  MD5Final(digest, &ctx);
  hexDump(digest, 16);
  printf("\nSource:\n");
  hexDump(buffer, 128);
  MD5Init(&ctx);
  MD5Update(&ctx, buffer, 128);
  MD5Final(digest, &ctx);
  printf("MD5 Hash:\n");
  hexDump(digest, 16);

  printf("\nSHA1\n");
  SHA1Context sha;
  printf("• SHA1Context √ (size: %lu bytes)\n", sizeof(sha));
  SHA1Reset(&sha);
  printf("• SHA1Reset √\n");
  SHA1Input(&sha, (const unsigned char *)SHA1_TESTA, strlen(SHA1_TESTA));
  printf("• SHA1Input √\n");
  SHA1Result(&sha);
  printf("• SHA1Result √\n");
  if (!sha.Computed) {
    printf("ERROR-- could not compute message digest\n");
  } else {
    printf("\t");
    for (int i = 0; i < 5; i++) {
      printf("%X ", sha.Message_Digest[i]);
    }
    printf("\n");
    printf("Should match:\n");
    printf("\t80A10644 B10E579C 6241B958 FA98F129 7C035CD8\n");
  }

  printf("\nCode39\n");
  n = c39GetSize(6);
  printf("c39GetSize(6): %d\n", n);
  char *buff = malloc(n);
  int rs = createCode39("TERRAFORM", 9, buff);
  printf("createCode39('terraform'): %d\n", rs);
  printf("\nBuffer\n=============\n");
  hexDump((unsigned char *)buff, rs);
  bmp_img c39img;
  int w = (rs*4) + 20;
  int h = 120;
  int px, py, pw;
  bmp_img_init_df(&c39img, w, h);
  unsigned char cr, cg, cb;
  for (px = 0; px < w; px++) {
    for(py = 0; py < h; py++) {
      bmp_pixel_init(&c39img.img_pixels[py][px], 255, 255, 255);
    }
  }
  for (px = 0; px < rs; px++) {
    char c = buff[px];
    if (c == 'x') {
      cr = 0;
      cg = 0;
      cb = 0;
    } else {
      cr = 255;
      cg = 255;
      cb = 255;
    }
    for(pw = 0; pw < 4; pw++) {
      for(py = 10; py < 100; py++) {
        bmp_pixel_init(&c39img.img_pixels[py][px*4+10+pw], cr, cg, cb);
      }
    }
  }
  bmp_img_write(&c39img, "c39.bmp");
  bmp_img_free(&c39img);
  free(buff);
  system("open c39.bmp");

  printf("\nBMP\n");
  bmp_img img;
  bmp_img_init_df(&img, 512, 512);
  for (size_t y = 0; y < 512; y++) {
    for (size_t x = 0; x < 512; x++) {
      bmp_pixel_init(&img.img_pixels[y][x], 255 * !(x & y), x ^ y, x | y);
    }
  }
  bmp_img_write(&img, "test.bmp");
  bmp_img_free(&img);
  system("open test.bmp");

  printf("\n\n\n\n");
  return 0;
}
