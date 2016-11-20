# This is a comment !
#
# ’myprogram’ is built from file1.c file2.c and file3.c
CC = gcc
CFLAGS = -Wall -g
OBJS = compressR_LOLS.o compressR_worker_LOLS.o compressT_LOLS.o

compression: $(OBJS)
	$(CC) -g -o compression $(OBJS) 

compressR_LOLS.o: compressR_LOLS.c compression.h
	$(CC) -c -g compressR_LOLS.c 

compressR_worker_LOLS.o: compressR_worker_LOLS.c compression.h
	$(CC) -c -g compressR_worker_LOLS.c

compressT_LOLS.o: compressT_LOLS.c compression.h
	$(CC) -c -g compressT_LOLS.c

clean:
	rm -rf *.o compression