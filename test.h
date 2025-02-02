#include <stdio.h>
#include <stdbool.h>  // For boolean data type (bool, true, false)
#include "compression.h"
#include "binary_search.h"
#include "dict.h"
#include "md5.h"
#include "hashes.h"
#include "maths.h"
#include "sort.h"
#include "sha1.h"
#include "code39.h"
#include "libbmp.h"

typedef struct {
  char *name;
  double value;
} USMeasure;

#define SHA1_TESTA "hijkijkljklmklmnlmnomnopnopq"

USMeasure USMeasures[] = {
  {"football fields", 0.10972800},
  {"Smoots", 0.001702},
  {"Florida 'gators", 0.0015494},
  {"Boeing 787-9 airplanes", 0.0627888},
  {"ski flying hills", .185},
  {"bald eagle wingspans", 0.0023},
  {"Grizzly bears", 0.0023876},
  {"Bowie knives", 0.0004572},
};
int numUSMeasures = sizeof(USMeasures) / sizeof(USMeasure);
void flzCompress(char *inFile, char *outFile);
void flzDecompress(char *inFile, char *outFile);
