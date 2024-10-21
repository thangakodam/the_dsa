# _*_ MakeFile _*_

# Compiler flags
CFLAGS = -Wall -Wextra -Wformat=2 -g -Wimplicit-fallthrough -Wconversion

# Directories & paths
BLD = ./build


# to build the library file for queue
build: $(BLD)/libqueue.a

# to test the queue implementation
test: $(BLD)/libqueue.a $(BLD)/tqueue
testrun: test
	$(BLD)/tqueue



# compile queue source to object file
$(BLD)/queue.o: queue.c queue.h
	gcc $(CFLAGS) -c $< -o $@

# generate a statically linked library file
$(BLD)/libqueue.a: $(BLD)/queue.o
	ar -rcs $@ $<

# compile test_stack.c and link it will libstack library
$(BLD)/tqueue: tests/test_queue.c queue.h
	gcc $(CFLAGS) $< -I . -l queue -L $(BLD) -o $@


clean:
	rm -rf $(BLD)/*