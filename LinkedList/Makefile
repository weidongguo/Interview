C = g++
ARG = -I. -Wall

a.out: test_linkedList.o linkedList.o
	$(C) test_linkedList.o linkedList.o $(ARG)	

test_linkedList.o: test_linkedList.cpp 
	$(C) -c test_linkedList.cpp $(ARG)

linkedList.o: linkedList.cpp
	$(C) -c linkedList.cpp $(ARG)

clean:
	rm -f *.o *.out
