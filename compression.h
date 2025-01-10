#ifndef H_COMPRESSION_H
#define H_COMPRESSION_H

#include <stdio.h>
#include <stdbool.h>  // For boolean data type (bool, true, false)
#include <stdlib.h>

#define MAX_TREE_HT 50

struct MinHNode {
  char item;
  unsigned freq;
  struct MinHNode *left, *right;
};

struct MinHeap {
  unsigned size;
  unsigned capacity;
  struct MinHNode **array;
};

// Function declaration
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

#endif
