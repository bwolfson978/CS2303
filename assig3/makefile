ctest: ctest.o mystring.o account.o
	gcc ctest.o mystring.o account.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

account.o: account.c account.h
	gcc -g -c account.c

clean: 
	rm -f mystring.o ctest.o account.o ctest

docs:
	doxygen
	chmod ugo+rwx -R html
	chmod go-w -R html
	cp -p -r ./html/* ~/public_html/cs2303assig3
	cp -p -r ./latex/* ~/public_html/cs2303assig3	


