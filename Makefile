run: compile
	./pam 4


compile:clus.o obj.o main.o
	gcc -o pam main.o obj.o clus.o


clus.o: clus.c fonction.h
	gcc -c clus.c

obj.o: obj.c fonction.h
	gcc -c obj.c

main.o: main.c fonction.h
	gcc -c main.c