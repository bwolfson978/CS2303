all: tnoderandom tnodetest queuetest stacktest 

tnoderandom: tnoderandom.o tnode.o
	gcc -g tnoderandom.o tnode.o -o tnoderandom

tnoderandom.o: tnoderandom.c tnode.h
	gcc -g -c tnoderandom.c

tnodetest: tnodetest.o tnode.o
	gcc -g tnodetest.o tnode.o -o tnodetest

tnodetest.o: tnodetest.c tnode.h
	gcc -g -c tnodetest.c

tnode.o: tnode.c tnode.h
	gcc -g -c tnode.c

queuetest: queuetest.o queue.o
	gcc -g queuetest.o queue.o -o queuetest

queue.o: queue.c queue.h
	gcc -g -c queue.c

queuetest.o: queuetest.c queue.h
	gcc -g -c queuetest.c

stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

stack.o: stack.c stack.h
	gcc -g -c stack.c

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig5

clean:
	rm -f *.o
	rm -f stacktest queuetest tnodetest tnoderandom
