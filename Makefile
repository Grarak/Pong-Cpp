CC	= g++
CFLAGS	= -Wall -g -c

OBJ	= main.o uiparent.o paddle.o ball.o point.o

pong: $(OBJ)
	$(CC) $(OBJ) -o pong -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

uiparent.o: uiparent.cpp uiparent.h
	$(CC) $(CFLAGS) uiparent.cpp

paddle.o: paddle.cpp paddle.h
	$(CC) $(CFLAGS) paddle.cpp

ball.o: ball.cpp ball.h
	$(CC) $(CFLAGS) ball.cpp

point.o: point.cpp point.h
	$(CC) $(CFLAGS) point.cpp

clean:
	rm *.o
	rm pong
