a.out: main.o server.o
	gcc main.o server.o
main.o: main.c server.h
	gcc -c main.c
sort_mimic_final.o:server.c server.h
	gcc -c server.c
