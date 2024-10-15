#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// data types to be used with stack
#define CHR  1
#define INT  2 
#define FLO  3
#define STR  4

#define STACK_EMPTY  -1      // -1 represents the stack is empty
#define STACKSIZE    100 


/* struct represents each element in the stack */
typedef struct {
  int etype;       // equals INT, FLO or STR, depending on the value type

  union {
    char   cval;
    int    ival;
    double fval;
    char   *sval;   
  } value;

} stack_element;

/* struct represents the stack */
typedef struct {
  int top;                 // index of top element
  stack_element **items;   // array of pointers to stack_elements struct
} stack;


/***** OPERATIONS ON STACK *****/
/**
 * Function to initialize a stack and returns it.
 * The size of stack is defined by macro 'STACKSIZE'.
 * Sets the top stack position to -1 (as stack is empty)
 * 
 * @return Returns pointer to 'stack' struct else NULL
 */
stack* Stack(void);

/**
 * Get no of elements in the stack.
 * 
 * @param[in] stack: Pointer to stack struct
 * @return Returns the items count in the stack.
 */
int stack_size(const stack *);

/**
 * Check if the stack is empty.
 * 
 * @param[in] stack: Pointer to stack struct
 * @return True if empty and False otherwise.
 */
bool is_stack_empty(const stack *);

/**
 * Check if the stack is full (ie. The entire STACKSIZE is occupied)
 * 
 * @param[in] stack: Pointer to stack struct
 * @return True if full and False otherwise.
 */
bool is_stack_full(const stack *);

/**
 * Free the memory allocated for stack and it's members.
 * 
 * @param[in] stack: Pointer to stack struct.
 */
void stack_destroy(stack *);

/**
 * Pushes the value at the top of the stack.
 * 
 * @param[in] stack: Pointer to stack struct.
 * @param[in] int: Value type, either of INT, FLO, STR
 * @param[in] void*: Pointer to the respective data value
 */
void stack_push(stack *, int, void *);

/**
 * Peek, to take a look at the top element in the stack.
 * 
 * @param[in] stack*: pointer to the stack struct
 * @return Returns a pointer to the stack_element in the top stack
 */
const stack_element* stack_peek(const stack *);

/**
 * Pops the top element of the stack and returns it.
 * 
 * @param[in] stack*: Pointer to the stack struct
 * @return Returns the pointer to the top stack_element
 */
stack_element* stack_pop(stack *);


/***** ADDITIONAL OPERATIONS ON STACK *****/
/**
 * Print all the elements of stack from top to bottom
 * 
 * @param[in] stack*: Pointer to stack struct
 */
void stack_print(stack *);