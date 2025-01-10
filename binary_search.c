#include "binary_search.h"

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

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[], int V) {
  // Initialize min value
  int min = INT_MAX, min_index;
  for (int v = 0; v < V; v++)
    if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;
  return min_index;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void Dijkstra(int V, int graph[V][V], int src, int* dist) {
  // The output array. dist[i] will hold the // shortest
  // distance from src to i
  bool sptSet[V];
  // sptSet[i] will be true if vertex i is included in shortest
  // path tree or shortest distance from src to i is finalized
  // Initialize all distances as INFINITE and stpSet[] as false
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;
  // Distance of source vertex from itself is always 0
  dist[src] = 0;
  // Find shortest path for all vertices
  for (int count = 0; count < V - 1; count++) {
    // Pick the minimum distance vertex from the set of
    // vertices not yet processed. u is always equal to
    // src in the first iteration.
    int u = minDistance(dist, sptSet, V);
    // Mark the picked vertex as processed
    sptSet[u] = true;
    // Update dist value of the adjacent vertices of the picked vertex.
    for (int v = 0; v < V; v++)
      // Update dist[v] only if is not in sptSet,
      // there is an edge from u to v, and total
      // weight of path from src to  v through u is
      // smaller than current value of dist[v]
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }
}

// Comparator function to use in sorting
int comparator(const void* p1, const void* p2) {
  const int(*x)[3] = p1;
  const int(*y)[3] = p2;
  return (*x)[2] - (*y)[2];
}

// Initialization of parent[] and rank[] arrays
void makeSet(int parent[], int rank[], int n) {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}

// Function to find the parent of a node
int findParent(int parent[], int component) {
  if (parent[component] == component)
    return component;
  return parent[component] = findParent(parent, parent[component]);
}

// Function to unite two sets
void unionSet(int u, int v, int parent[], int rank[], int n) {
  // Finding the parents
  u = findParent(parent, u);
  v = findParent(parent, v);
  if (rank[u] < rank[v]) {
    parent[u] = v;
  } else if (rank[u] > rank[v]) {
    parent[v] = u;
  } else {
    parent[v] = u;
    // Since the rank increases if
    // the ranks of two sets are same
    rank[u]++;
  }
}
