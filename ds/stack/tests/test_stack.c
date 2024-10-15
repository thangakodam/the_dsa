#include "stack.h"


int main() {
  // Create a stack
  stack *myStack = Stack();
  if (myStack == NULL) {
      return EXIT_FAILURE; // Exit if stack creation failed
  }

  // Test pushing characters
  char char_val = 'A';
  stack_push(myStack, CHR, &char_val);

  char char_val2 = '{';
  stack_push(myStack, CHR, &char_val2);

  // Test pushing integers
  int intValue1 = 42;
  stack_push(myStack, INT, &intValue1);
  
  int intValue2 = 84;
  stack_push(myStack, INT, &intValue2);

  // Test pushing a double
  double floatValue = 3.14;
  stack_push(myStack, FLO, &floatValue);

  // Test pushing a string
  const char *strValue = "Hello, Stack!";
  stack_push(myStack, STR, (void *)strValue);

  // Check the size of the stack
  printf("Stack size: %d\n", stack_size(myStack));

  // print all the elements in stack
  puts("Printing the entire stack:");
  stack_print(myStack);
  puts(" ");

  // Peek at the top element
  const stack_element *topElement = stack_peek(myStack);
  if (topElement != NULL) {
    printf("Top element (string): %s\n", topElement->value.sval);
  }

  // Pop elements from the stack
  stack_element *poppedElement;
  while ((poppedElement = stack_pop(myStack)) != NULL) {
    switch (poppedElement->etype) {
      case CHR:
        printf("Popped character: %c\n", poppedElement->value.cval);
        break;
      case INT:
        printf("Popped integer: %d\n", poppedElement->value.ival);
        break;
      case FLO:
        printf("Popped float: %f\n", poppedElement->value.fval);
        break;
      case STR:
        printf("Popped string: %s\n", poppedElement->value.sval);
        free(poppedElement->value.sval); // Free the string memory
        break;
    }
      free(poppedElement); // Free the stack_element itself
  }

  // Free the stack
  stack_destroy(myStack);

  return EXIT_SUCCESS;
}
