CC=gcc
CFLAGS=-g
INCLUDE=
LIBS=

OBJS= t_main.o d_queue.o
TAGT=test

$(TAGT):$(OBJS)
	$(CC) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm *.o $(TAGT)
