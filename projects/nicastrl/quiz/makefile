CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc -o testme testme.c $(CFLAGS)
	
testQuiz: testme
	./testme

all: testme
	
default: testme testQuiz

clean:
	rm -f testme *.o *.gcov *.gcda *.gcno *.out 