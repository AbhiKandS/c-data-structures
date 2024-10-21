CC=gcc
BINS=bin/rev bin/postfix
OBJS_REV=obj/scan.o obj/stack.o
OBJS_POSTFIX=obj/stack.o obj/scan.o

all: $(BINS)

obj/%.o: src/%.c
	$(CC) -o $@ -c $<

bin/rev: $(OBJS_REV) ReverseStringStack.c
	$(CC) -o $@ $^

bin/postfix: $(OBJS_POSTFIX) InfixPostfix.c
	$(CC) -o $@ $^

clean:
	rm -r bin/*dSYM $(OBJS_REV) $(BINS) $(OBJS_POSTFIX)
