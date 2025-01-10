all: test_sink dylib

test_sink:
	gcc -Wall -O3 -g -c *.c
	g++ -Wall -O3 -g -c flzp.cpp
	gcc *.o -o test_sink
	rm test.o

dylib:
	gcc -dynamiclib *.o -o kitchen_sink.dylib

clean:
	rm *.o *.dylib test_sink
	rm -rf Builds\ -\ Kitchen_Sink/

test: test_sink
	./test_sink
	python3 ./test_sink.py
