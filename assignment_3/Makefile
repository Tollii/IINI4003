CC=g++
CFLAGS=-O3

.PHONY: all clean 

all: task_4

%.o: %.cpp 
	$(CC) -c $(CFLAGS) $< -o $@ 

task_4: task_4.o
	$(CC) -o task_4 task_4.o

clean:
	rm -f *.o task_4

