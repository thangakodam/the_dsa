#include "stack.h"

/* LOGIC:
 *  - go through the expression and push in to stack if it is a opening parentheses
 *  - if its closing parentheses, then pop the last element and
 *      check if it's matching opening parentheses, if not return false
 *  - continue doing it until end of expression is reached
 *  - check the length of stack, if not empty then there is not matching parentheses
*/
bool validate_expression(char *expr) {
  // stack to hold the parentheses
  stack *paren = Stack();

  for (int i = 0; i < strlen(expr); i++) {
    // if the symbol is of opening type, then push it to stack
    if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{' || expr[i] == '<') {
      stack_push(paren, CHR, &expr[i]);
      continue;
    }

    // if symbol is of closing type, then the last push in symbol should matches it
    if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}' || expr[i] == '>') {
      // if this is the first symbol in string then stack will be empty
      if (is_stack_empty(paren)) return false;

      stack_element *element = stack_pop(paren);

      switch(expr[i]) {
        case ')':
          if (element->value.cval != '(') return false;
          break;
        case ']':
          if (element->value.cval != '[') return false;
          break;
        case '}':
          if (element->value.cval != '{') return false;
          break;
        case '>':
          if (element->value.cval != '<') return false;
          break;
      }    
    }
  }

  // if the stack is empty, then all opening parentheses has a matching closing parentheses
  if (!is_stack_empty(paren)) return false;

  return true;
}



int main() {
  char input_1[] = "(A + B)";
  char input_2[] = "{[A + B] - [(C - D)]";
  char input_3[] = "(A + B) - {C - D} - [F + G]";
  char input_4[] = "((H) * {([J + K])})";
  char input_5[] = "(((A)))";

  puts("Is the expression is valid: ");
  if (validate_expression(input_5)) puts("YES");
  else puts("NO");

  return 0;
}