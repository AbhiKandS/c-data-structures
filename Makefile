CC=gcc
BINS=bin/rev bin/postfix
OBJS_REV=src/scan.o src/stack.o
OBJS_POSTFIX=src/stack.o

all: $(BINS)

%.o: %.c
	$(CC) -o $@ -c $<

bin/rev: $(OBJS_REV) ReverseStringStack.c
	$(CC) -o $@ $^

bin/postfix: $(OBJS_POSTFIX) InfixPostfix.c
	$(CC) -o $@ $^

clean:
	rm -r bin/*dSYM $(OBJ) $(BINS)