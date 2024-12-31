from ctypes import *
import platform

pl = platform.system()
if pl == 'Darwin':
  kitchen_sink = CDLL('./kitchen_sink.dylib')
elif pl == 'Linux':
  kitchen_sink = CDLL('./kitchen_sink.so')

print("bubbleSortInt")
py_values0 = [89, 12, 33, 23, 127, 24, 10, 40]
n = len(py_values0)
print(py_values0)
arr = (c_int * len(py_values0))(*py_values0)
kitchen_sink.bubbleSortInt(arr, len(py_values0))
print(arr[:])

print("insertionSortInt")
py_values1 = [89, 12, 33, 23, 127, 24, 10, 40]
n = len(py_values1)
print(py_values1)
arr = (c_int * len(py_values1))(*py_values1)
kitchen_sink.insertionSortInt(arr, len(py_values1))
print(arr[:])

print("mergeSortInt")
py_values2 = [89, 12, 33, 23, 127, 24, 10, 40]
n = len(py_values2)
print(py_values2)
arr = (c_int * n)(*py_values2)
kitchen_sink.mergeSortInt(arr, 0, n-1)
print(arr[:])

print("quickSortInt")
py_values3 = [89, 12, 33, 23, 127, 24, 10, 40]
n = len(py_values3)
print(py_values3)
arr = (c_int * len(py_values3))(*py_values3)
kitchen_sink.quickSortInt(arr, 0, len(py_values3)-1)
print(arr[:])

print("\niterativeBinarySearch")
query = 40
result = kitchen_sink.iterativeBinarySearch(arr, 0, n - 1, query)
if (result == -1):
  print(f" • Element {query} is not present in array!")
else:
  print(f" • Element {query} is present at index {result}")
query = 41
result = kitchen_sink.iterativeBinarySearch(arr, 0, n - 1, query)
if (result == -1):
  print(f" • Element {query} is not present in array!")
else:
  print(f" • Element {query} is present at index {result}")

print("\nrecursiveBinarySearch")
query = 40
result = kitchen_sink.recursiveBinarySearch(arr, 0, n - 1, query)
if (result == -1):
  print(f" • Element {query} is not present in array!")
else:
  print(f" • Element {query} is present at index {result}")
query = 41
result = kitchen_sink.recursiveBinarySearch(arr, 0, n - 1, query)
if (result == -1):
  print(f" • Element {query} is not present in array!")
else:
  print(f" • Element {query} is present at index {result}")

a = 10
b = 15
print(f"\nGCD({a}, {b}) = {kitchen_sink.basicGCD(a, b)}")
a = 35
b = 10
print(f"GCD({a}, {b}) = {kitchen_sink.basicGCD(a, b)}")
a = 31
b = 2
print(f"GCD({a}, {b}) = {kitchen_sink.basicGCD(a, b)}")
a = 99
b = 12
print(f"GCD({a}, {b}) = {kitchen_sink.basicGCD(a, b)}")

print("\n\n\n\n");
