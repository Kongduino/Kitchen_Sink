#include "sort.h"

void bubbleSortInt(int array[], int size) {
  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        // ping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void bubbleSortDouble(double array[], int size) {
  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        // swapping occurs if elements
        // are not in the intended order
        double temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void insertionSortInt(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    // Compare key with each element on the left of it
    // until an element smaller is found.
    // For descending order, change key<array[j] to key>array[j].
    while (j >= 0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void insertionSortDouble(double array[], int size) {
  for (int step = 1; step < size; step++) {
    double key = array[step];
    int j = step - 1;
    // Compare key with each element on the left of it
    // until an element smaller is found.
    // For descending order, change key<array[j] to key>array[j].
    while (j >= 0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

// Merge two subarrays L and M into arr
void mergeInt(int arr[], int p, int q, int r) {
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSortInt(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
    mergeSortInt(arr, l, m);
    mergeSortInt(arr, m + 1, r);
    // Merge the sorted subarrays
    mergeInt(arr, l, m, r);
  }
}

// Merge two subarrays L and M into arr
void mergeDouble(double arr[], int p, int q, int r) {
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  double L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSortDouble(double arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
    mergeSortDouble(arr, l, m);
    mergeSortDouble(arr, m + 1, r);
    // Merge the sorted subarrays
    mergeDouble(arr, l, m, r);
  }
}

// function to find the partition position
int qsPartitionInt(int array[], int low, int high) {
  // select the rightmost element as pivot
  int pivot = array[high];
  // pointer for greater element
  int i = (low - 1);
  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      // swap element at i with element at j
      int t = array[i];
      array[i] = array[j];
      array[j] = t;
    }
  }
  // swap the pivot element with the greater element at i
  int t = array[i + 1];
  array[i + 1] = array[high];
  array[high] = t;
  // return the partition point
  return (i + 1);
}

void quickSortInt(int array[], int low, int high) {
  if (low < high) {
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = qsPartitionInt(array, low, high);
    // recursive call on the left of pivot
    quickSortInt(array, low, pi - 1);
    // recursive call on the right of pivot
    quickSortInt(array, pi + 1, high);
  }
}

// function to find the partition position
int qsPartitionDouble(double array[], int low, int high) {
  // select the rightmost element as pivot
  double pivot = array[high];
  // pointer for greater element
  int i = (low - 1);
  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      // swap element at i with element at j
      double t = array[i];
      array[i] = array[j];
      array[j] = t;
    }
  }
  // swap the pivot element with the greater element at i
  double t = array[i + 1];
  array[i + 1] = array[high];
  array[high] = t;
  // return the partition point
  return (i + 1);
}

void quickSortDouble(double array[], int low, int high) {
  if (low < high) {
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = qsPartitionDouble(array, low, high);
    // recursive call on the left of pivot
    quickSortDouble(array, low, pi - 1);
    // recursive call on the right of pivot
    quickSortDouble(array, pi + 1, high);
  }
}

// Function to get the maximum value in the array
int getMaxInt(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}
