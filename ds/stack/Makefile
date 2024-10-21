# _*_ MakeFile _*_

# Compiler flags
CFLAGS = -Wall -Wextra -Wformat=2 -g -Wimplicit-fallthrough -Wconversion

# Directories & paths
BLD = ./build


# to build the library file for stack
build: $(BLD)/libstack.a

# to test the stack implementation
test: $(BLD)/libstack.a $(BLD)/tstack
testrun: test
	$(BLD)/tstack


# compile stack source to object file
$(BLD)/stack.o: stack.c stack.h
	gcc $(CFLAGS) -c $< -o $@

# generate a statically linked library file
$(BLD)/libstack.a: $(BLD)/stack.o
	ar -rcs $@ $<


# compile test_stack.c and link it will libstack library
$(BLD)/tstack: tests/test_stack.c stack.h
	gcc $(CFLAGS) $< -I . -l stack -L $(BLD) -o $@


clean:
	rm -rf $(BLD)/*