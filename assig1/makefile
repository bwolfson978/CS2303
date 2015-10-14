all: lab1 num leap

lab1: lab1.o
	gcc lab1.o --std=gnu89 -o lab1

lab1.o: lab1.c
	gcc --std=gnu89 -c lab1.c

leap: leap.o
	gcc leap.o --std=c99 -o leap

leap.o: leap.c
	gcc --std=c99 -c leap.c

num: num.o grade_info.o 
	gcc num.o grade_info.o --std=c99 -o num

num.o: num.c grade_info.c
	gcc --std=c99 -c num.c
	gcc --std=c99 -c grade_info.c

grade_info.o: grade_info.c grade_info.h
	gcc --std=c99 -c grade_info.c

clean: 
	rm -f lab1.o lab1 num.o num leap.o leap
