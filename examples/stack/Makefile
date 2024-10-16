# location to stack static library
LIB = ../../ds/stack/build
INC = ../../ds/stack/

# Compiler flags
CFLAGS = -Wall -Wextra -Wformat=2 -g -Wimplicit-fallthrough -Wconversion


# Problem - 01 (validate_expression)
prob1: validate_expression
	./validate_expression

validate_expression: validate_expression.c
	gcc $(CFLAGS) $< -I $(INC) -l stack -L $(LIB) -o $@


# Problem - 02 ()


clean:
	rm -f validate_expression