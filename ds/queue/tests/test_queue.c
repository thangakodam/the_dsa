#include <assert.h>

#include "queue.h"

int main() {
  // Test 1: Check if the queue is created successfully
  queue *q = Queue();
  assert(q != NULL);

  // Test 2: Check if the items array is allocated
  assert(q->items != NULL);

  // Test 3: Check initial values of front and rear
  assert(q->front == QUEUE_EMPTY); 
  assert(q->rear == QUEUE_EMPTY);

  // Test 4: Insert a character
  char char_val = 'A';
  assert(queue_insert(q, CHR, &char_val) == true);
  assert(q->items[0]->etype == CHR);
  assert(q->items[0]->value.cval == 'A');

  // Test 5: Insert an integer
  int i = 42;
  assert(queue_insert(q, INT, &i) == true);
  assert(q->items[1]->etype == INT);
  assert(q->items[1]->value.ival == 42);

  // Test 6: Insert a float
  double f = 3.14;
  assert(queue_insert(q, FLO, &f) == true);
  assert(q->items[2]->etype == FLO);
  assert(q->items[2]->value.fval == 3.14);

  // Test 7: Insert a string
  char *str = "Hello";
  assert(queue_insert(q, STR, str) == true);
  assert(q->items[3]->etype == STR);
  assert(strcmp(q->items[3]->value.sval, "Hello") == 0);

  // Test 8: Check queue state after multiple inserts
  assert(q->front == 0);
  assert(q->rear == 3);           // Since we have inserted 4 elements (0 to 3)

  // Printing the Queue
  queue_print(q);

  // Test 9: Remove an element from the queue
  queue_element *removed_element = queue_remove(q);
  assert(removed_element != NULL);
  assert(removed_element->etype == CHR);
  assert(removed_element->value.cval == 'A');
  free(removed_element); // Free the removed element

  // Test 10: Remove another element
  removed_element = queue_remove(q);
  assert(removed_element != NULL);
  assert(removed_element->etype == INT);
  assert(removed_element->value.ival == 42);
  free(removed_element); // Free the removed element

  // Test 11: Remove a float
  removed_element = queue_remove(q);
  assert(removed_element != NULL);
  assert(removed_element->etype == FLO);
  assert(removed_element->value.fval == 3.14);
  free(removed_element); // Free the removed element

  // Test 12: Remove a string
  removed_element = queue_remove(q);
  assert(removed_element != NULL);
  assert(removed_element->etype == STR);
  assert(strcmp(removed_element->value.sval, "Hello") == 0);
  free(removed_element->value.sval); // Free the string
  free(removed_element); // Free the removed element

  // Test 11: Check if the queue is empty after all removals
  assert(is_queue_empty(q) == true);

  // Test 12: Attempt to insert into a full queue
  for (int j = 0; j < QUEUE_SIZE; j++)
    assert(queue_insert(q, INT, &i) == true); // Fill the queue

  assert(queue_insert(q, INT, &i) == false); // This should fail (queue overflow)

  puts("so far so good");

  return 0;
}