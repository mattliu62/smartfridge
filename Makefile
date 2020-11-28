CC = g++ -std=c++14
CFLAGS = -g -I/usr/include/jsoncpp

CORE_INCS = food.h fridge.h
CORE_OBJS = food.o fridge.o

LDFLAGS = -ljsoncpp

all: mcfreezy

food.o: food.h
	$(CC) -c $(CFLAGS) food.cpp

fridge.o: fridge.h food.h
	$(CC) -c $(CFLAGS) fridge.cpp

main.o: main.cpp $(CORE_INCS)
	$(CC) -c $(CFLAGS) main.cpp

mcfreezy: $(CORE_OBJS) main.o
	$(CC) -o mcfreezy $(CORE_OBJS) main.o $(LDFLAGS)

clean: 
	rm -f *.o *~ mcfreezy