#ifndef H_BINSEARCH_H
#define H_BINSEARCH_H

#include <stdio.h>
#include <stdbool.h> // For boolean data type (bool, true, false)
#include <limits.h>

void quickSortInt(int array[], int low, int high);
int iterativeBinarySearch(int arr[], int low, int high, int x);
int recursiveBinarySearch(int arr[], int low, int high, int x);
int minDistance(int dist[], bool sptSet[], int V);
void Dijkstra(int V, int graph[V][V], int src, int* dist);

#endif