CC=gcc
CFLAGS=-g
INCLUDE=
LIBS=-lpthread

OBJS= t_main.o d_queue.o d_message.o d_mutex.o d_common.o
TAGT=test

$(TAGT):$(OBJS)
	$(CC) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm *.o $(TAGT)
