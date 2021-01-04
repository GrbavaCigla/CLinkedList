OBJS	= main.o
SOURCE	= main.c
HEADER	= 
OUT	= clinklist
CC	 = gcc
FLAGS	 = -O3 -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

clean:
	rm -f $(OBJS) $(OUT)
