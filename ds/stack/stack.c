#include "stack.h"



stack* Stack(void) {
  // allocate memory for 'stack' struct
  stack *s = malloc( sizeof(stack) );
  if (s == NULL) {
    perror("Stack(): Stack allocation failed");

    return NULL;
  }

  // array containing pointers to stack_element struct
  s->items = malloc( STACKSIZE * sizeof(stack_element *) );
  if (s->items == NULL) {
    perror("Stack(): Items array allocation failed");

    free(s);
    return NULL;
  }

  // top of stack set to -1, as no items are pushed into stack
  s->top = STACK_EMPTY;

  return s;
}


int stack_size(const stack *s) {
  return s->top + 1;
}


bool is_stack_empty(const stack *s) {
  return (s->top == STACK_EMPTY);
}


bool is_stack_full(const stack *s) {
  return (s->top == STACKSIZE - 1);
}


void stack_destroy(stack *s) {
  if (s == NULL) return;     // check for NULL

  // free each stack_element in the array
  for (int i = s->top; i >= 0; i--)
    free(s->items[i]);
  
  free(s->items);   // free the items array
  free(s);          // free the stack struct
}


void stack_push(stack *s, int etype, void *val) {
  if (is_stack_full(s)) {
    perror("stack_push(): Stack Overflow");
    return;
  }

  // allocate memory for stack_element struct
  stack_element *element = malloc( sizeof(stack_element) );
  if (element == NULL) {
    perror("stack_push(): stack_element creation failed");
    return;
  }

  switch (etype) {
    case CHR:
      element->value.cval = *(char *)val;
      break;
    case INT:
      element->value.ival = *(int *)val;
      break;
    case FLO:
      element->value.fval = *(double *)val;
      break;
    case STR: {
      // length of the string including the null character
      size_t char_cnt = strlen( (char *)val ) + 1;

      // allocate memory of size 'char_cnt'
      element->value.sval = malloc(char_cnt * sizeof(char));
      if (element->value.sval == NULL) {
        perror("stack_push(): string creation failed");
        free(element);
        return;
      }

      // copy the memory contents from val to element struct
      memcpy(element->value.sval, val, char_cnt);
      break;
    }
    default: {
      perror("stack_push(): Invalid element type.");
      free(element);
      return;
    }
  }

  // updating the value type
  element->etype = etype;

  // finally, adding the stack_element to the stack array
  s->top++;
  s->items[s->top] = element;
}


const stack_element* stack_peek(const stack *s) {
  if (is_stack_empty(s)) {
    perror("stack_peek(): Stack Underflow");
    return NULL;
  }

  return s->items[s->top];
}


stack_element* stack_pop(stack *s) {
  if (is_stack_empty(s)) {
    perror("stack_pop(): Stack Underflow");
    return NULL;
  }

  return s->items[s->top--];
}


void stack_print(stack *s) {
  for (int i = s->top; i >= 0; i--) {
    // print the index
    printf("%3d", i);

    // print element type and it's value
    switch (s->items[i]->etype) {
      case CHR:
        printf(" %3s %20c \n", "CHR", s->items[i]->value.cval);
        break;
      case INT:
        printf(" %3s %20d \n", "INT", s->items[i]->value.ival);
        break;
      case FLO:
        printf(" %3s %20.3f \n", "FLO", s->items[i]->value.fval);
        break;
      case STR:
        printf(" %3s %20s \n", "STR", s->items[i]->value.sval);
        break;
    }
  }
} 