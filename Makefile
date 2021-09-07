CC=g++
CFLAGS=-I -Wall
DEPS = log.h
OBJ = main.o log.o
EXEC = driver

ass1: $(EXEC)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


clean: 
	rm -f *.o $(EXEC)
