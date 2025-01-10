#ifndef __SORT__H
#define __SORT__H
#include <stdio.h>

void bubbleSortInt(int array[], int size);
void bubbleSortDouble(double array[], int size);
void insertionSortInt(int array[], int size);
void insertionSortDouble(double array[], int size);
// Merge two subarrays L and M into arr
void mergeInt(int arr[], int p, int q, int r);
// Divide the array into two subarrays, sort them and merge them
void mergeSortInt(int arr[], int l, int r);
// Merge two subarrays L and M into arr
void mergeDouble(double arr[], int p, int q, int r);
// Divide the array into two subarrays, sort them and merge them
void mergeSortDouble(double arr[], int l, int r);
// function to find the partition position
int qsPartitionInt(int array[], int low, int high);
void quickSortInt(int array[], int low, int high);
// function to find the partition position
int qsPartitionDouble(double array[], int low, int high);
void quickSortDouble(double array[], int low, int high);
// Function to get the maximum value in the array
int getMaxInt(int array[], int n);
#endif
