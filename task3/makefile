CC = gcc
CFLAGS = -g -O2 -lm
OBJ = main.o list.o
TARGET = task3

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c list.h
	$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean