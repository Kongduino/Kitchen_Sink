all: test_sink dylib

test_sink:
	gcc -Wall -O3 -g -c *.c
	gcc *.o -o test_sink
	./test_sink

dylib:
	gcc -dynamic binary_search.o hashes.o sieve.o sort.o test.o -o kitchen_sink.dylib
	python3 ./test_sink.py

clean:
	rm *.o *.dylib test_sink
	rm -rf Builds\ -\ Kitchen_Sink/

