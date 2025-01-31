from ctypes import *
import platform, random, sys
from PIL import Image, ImageDraw, ImageFont

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
print(f"LCM({a}, {b}) = {kitchen_sink.basicLCM(a, b)}")
a = 35
b = 10
print(f"GCD({a}, {b}) = {kitchen_sink.basicGCD(a, b)}")
print(f"LCM({a}, {b}) = {kitchen_sink.basicLCM(a, b)}")
a = 31
b = 2
print(f"GCD({a}, {b}) = {kitchen_sink.basicGCD(a, b)}")
print(f"LCM({a}, {b}) = {kitchen_sink.basicLCM(a, b)}")
a = 99
b = 12
print(f"GCD({a}, {b}) = {kitchen_sink.basicGCD(a, b)}")
print(f"LCM({a}, {b}) = {kitchen_sink.basicLCM(a, b)}")

yesno = ["no", "yes"]
x = c_int(764587)
rslt = kitchen_sink.isPrime(x)
s = "prime"
if rslt ==0:
  s = "not " + s
print(f"\n764587 is {s}")
x = c_int(65536)
rslt = kitchen_sink.isPrime(x)
s = "prime"
if rslt ==0:
  s = "not " + s
print(f"65536 is {s}")

print(f"\nLeap Years:\n==============")
years = { 1900, 1967, 1954, 1988, 2000, 2024 }
for y in years:
  rslt = kitchen_sink.isLeapYear(y)
  rslt = yesno[rslt]
  print(f"Is {y} a leap year: {rslt}")

USMeasures = [
  ["football fields", 0.10972800],
  ["Smoots", 0.001702],
  ["Florida 'gators", 0.0015494],
  ["Boeing 787-9 airplanes", 0.0627888],
  ["ski flying hills", .185],
  ["bald eagle wingspans", 0.0023],
  ["Grizzly bears", 0.0023876],
  ["Bowie knives", 0.0004572],
]

print(f"\nHAVERSINE:\n=============");
lat0 = 22.4
lat1 = 22.4
long0 = 113.9
long1 = 114.0
km = kitchen_sink.haversine(c_float(lat0), c_float(long0), c_float(lat1), c_float(long1), 1)
mi = km / 1.609344
x = USMeasures[random.randint(0, len(USMeasures)-1)]
print(f"Distance between {lat0}, {long0} and {lat1}, {long1}:\n • {km} km for normal people,\n • or for Muricans, {(km / x[1])} {x[0]} ({mi} mi)")

myV = 9
graph = [
   0, 4, 0, 0, 0, 0, 0, 8, 0,
   4, 0, 8, 0, 0, 0, 0, 11, 0,
   0, 8, 0, 7, 0, 4, 0, 0, 2,
   0, 0, 7, 0, 9, 14, 0, 0, 0,
   0, 0, 0, 9, 0, 10, 0, 0, 0,
   0, 0, 4, 14, 10, 0, 2, 0, 0,
   0, 0, 0, 0, 0, 2, 0, 1, 6,
   8, 11, 0, 0, 0, 0, 1, 0, 7,
   0, 0, 2, 0, 0, 0, 6, 7, 0
]
dist = [0] * myV
distArr = (c_int * myV)(*dist)
arr = (c_int * int(myV * myV))(*graph)
source = 0
kitchen_sink.Dijkstra(myV, arr, source, distArr)

print("\n\nGraph:\n        0    1    2    3    4    5    7    8    9\n====================================================\n")
for b in range(0, myV):
  s = f" {b} |"
  for a in range(0, myV):
      s += f"{graph[a+myV*b]: 5}"
  print(f"{s} |")
print("====================================================\n\n")

print("\nVertex \t\tDistance from source = {source}\n")
for i in range(0, myV):
  print(f"   {i} \t\t\t{distArr[i]}")

print("\nSHA1:")
SHA1_TESTA = b"hijkijkljklmklmnlmnomnopnopq"
arr = (c_char * len(SHA1_TESTA))(*SHA1_TESTA)
sha = b'\x00' * 104
sha_arr = (c_char * 104)(*sha)
kitchen_sink.SHA1AllInOne(arr, 28, sha_arr)
s0 = "\n• Hash:\t"
s = ""
for i in range (0, 5):
  n = i * 4
  a = sha_arr[n : n + 4]
  for j in range(0, 4):
    p = ord(sha_arr[n + 3 - j])
    s = s + f"{p:02X}"
  s += " "
s = s.strip()
print(s0+s)
print("Expecting:")
print("\t80A10644 B10E579C 6241B958 FA98F129 7C035CD8")
if (s == "80A10644 B10E579C 6241B958 FA98F129 7C035CD8"):
  print("Match!")
else:
  print("Fail!")

n = kitchen_sink.c39GetSize(9)
myText = b"Code39 Test"
tLen = len(myText)
print(f"c39GetSize(tLen): {n}")
buffer = create_string_buffer(n)
barWidth = 4
barHeight = 120
rs = kitchen_sink.createCode39(myText, tLen, buffer)
print(f"createCode39: {rs}")
if rs < 1:
  print("Error!")
  sys.exit(1)
nChunks = int(rs/(tLen+2))
print(f"Number of chunks per char: {nChunks}")
w = 20 + 20 + (barWidth * rs)
h = 20 + 20 + barHeight
img = Image.new("RGB", (w, h)) 
px = 20
py = 20
draw = ImageDraw.Draw(img)
draw.rectangle([0, 0, w, h], fill = "#ffffff", outline = None, width = 1)
charPos = []
for i in range(0, rs):
  c = buffer[i:i+1]
  if c == b"x":
    draw.rectangle([px, 20, px + barWidth - 1, 20 + barHeight], fill = "#000000", outline = None, width = 1)
  xx = i % 9
  if i > nChunks-1 and i < rs - nChunks + 1:
    draw.rectangle([px, h-40, px + barWidth - 1, h], fill = "#ffffff", outline = None, width = 1)
  px += barWidth
  if i % nChunks == 0:
    charPos.append(px)
fnt = ImageFont.truetype("/System/Volumes/Data/usr/local/texlive/2024/texmf-dist/fonts/truetype/public/gnu-freefont/FreeMono.ttf", 40)
charPos.append(px)
px = 0
print(charPos)
for c in myText:
  ppx = charPos[px+1]
  ppx = ppx + int((charPos[px+2] - ppx) / 2)
  print(f"Drawing {chr(c)} at {ppx}")
  draw.text((ppx, h - 40), chr(c), font = fnt, fill = (0, 0, 0, 255))
  px += 1

img.show()

print("\n\n\n\n")
