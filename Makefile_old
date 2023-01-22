CC=gcc
CFLAGS=-I. -DSYMBOL1 -DSYMBOL2
DEPS = header1.h header2.h
OBJS = src1.o src2.o src3.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

cible: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 
	
clean:
	rm -f cible $(OBJS)
	
