#makefile for generating finance.out

CC = gcc
CFLAGS = -Wall -Werror -ansi 

Finance.out: main.o Finance.o GeneralHelperMethods.o printMenus.o
	$(CC) $(CFLAGS) -o Finance.out main.o Finance.o GeneralHelperMethods.o printMenus.o -lm

main.o: main.c database.h generalHelperMethods.h
	$(CC) $(CFLAGS) -c -o main.o main.c

Finance.o: Finance.c database.h
	$(CC) $(CFLAGS) -c -o Finance.o Finance.c

GeneralHelperMethods.o: GeneralHelperMethods.c generalHelperMethods.h
	$(CC) $(CFLAGS) -c -o GeneralHelperMethods.o GeneralHelperMethods.c

printMenus.o: printMenus.c database.h
	$(CC) $(CFLAGS) -c -o printMenus.o printMenus.c

clean:
	rm main.o Finance.o GeneralHelperMethods.o printMenus.o Finance.out
