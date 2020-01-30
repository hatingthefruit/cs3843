CC = gcc

CFLAGS = -g -Wall

TARGET = Lab1

all: $(TARGET)
	./Lab1 > test.out
	diff test.out Lab1.out

$(TARGET): AndrewDiCarloLab1methods.c Lab1main.c
	$(CC) $(CFLAGS) Lab1main.c AndrewDiCarloLab1methods.c -o $(TARGET) 

clean:
	rm $(TARGET)