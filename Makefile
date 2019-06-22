.PHONY: all clean start test
NAME = graph

CFLAGS=-Wall -Wextra -pedantic -std=c11
	
all: graph
	
clean:
			rm -rf $(NAME) *.o
main.o: main.c
			gcc -c -o main.o main.c
graph.o: graph.c
			gcc -c -o $(NAME).o $(NAME).c
test.o: test.c
			gcc -c -o test.o test.c
graph: main.o graph.o test.o
			gcc $(CFLAGS) -o graph main.o lib1.a
start:
			./graph notest test2.txt out2.txt
test:
			./graph test
			 
