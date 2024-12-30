// C program to implement iterative Binary Search
#include <stdio.h>

// An iterative binary search function.
int iterativeBinarySearch(int arr[], int low, int high, int x) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    // Check if x is present at mid
    if (arr[mid] == x)
      return mid;
    // If x greater, ignore left half
    if (arr[mid] < x)
      low = mid + 1;
    // If x is smaller, ignore right half
    else
      high = mid - 1;
  }
  // If we reach here, then element was not present
  return -1;
}

// A recursive binary search function. It returns
// location of x in given array arr[low..high] is present,
// otherwise -1
int recursiveBinarySearch(int arr[], int low, int high, int x) {
  if (high >= low) {
    int mid = low + (high - low) / 2;
    // If the element is present at the middle
    // itself
    if (arr[mid] == x)
      return mid;
    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arr[mid] > x)
      return recursiveBinarySearch(arr, low, mid - 1, x);
    // Else the element can only be present
    // in right subarray
    return recursiveBinarySearch(arr, mid + 1, high, x);
  }
  return -1;
}
