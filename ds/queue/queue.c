#include "queue.h"

queue* Queue(void) {
  queue *q = malloc( sizeof(queue) );
  if (q == NULL) {
    perror("Queue(): Queue allocation failed");
    return NULL;
  }

  // array containing pointers to queue_element stuct
  q->items = malloc( QUEUE_SIZE * sizeof(queue_element *) );
  if (q->items == NULL) {
    perror("Queue(): Items array allocation failed");
    
    free(q);
    return NULL;
  }

  // set the front and rear values
  q->front = q->rear = QUEUE_EMPTY;

  return q;
}



bool is_queue_empty(const queue *q) {
  return (q->rear == QUEUE_EMPTY);
}



bool is_queue_full(const queue *q) {
  return (q->rear >= QUEUE_SIZE - 1);
}



int queue_size(const queue *q) {
  return (q->rear == QUEUE_EMPTY ? 0 : q->rear + 1);
} 



bool queue_insert(queue *q, int etype, void *data) {
  // is the queue is full ?
  if (is_queue_full(q)) {
    perror("queue_insert(): Queue Overflow");
    return false;
  }

  // memory allocation for new queue_element
  queue_element *element = malloc( sizeof(queue_element) );
  if (element == NULL) {
    perror("queue_insert(): queue_element allocation failed.");
    return false;
  }

  switch (etype) {
    case CHR:
      element->value.cval = *(char *) data;
      break;
    case INT:
      element->value.ival = *(int *) data;
      break;
    case FLO:
      element->value.fval = *(double *) data;
      break;
    case STR: {
      // get the length of string including NULL character
      unsigned long str_len = strlen( (char *) data );

      // allocate memory for new string data
      element->value.sval = malloc( str_len * sizeof(char) );
      if (element->value.sval == NULL) {
        perror("queue_insert(): string allocation failed.");

        free(element);
        return false;
      }

      // copy contents from data to struct union
      memcpy(element->value.sval, data, str_len);
      break;
    }
    default: {
      perror("queue_insert(): Invalid element type.");
      free(element);
      return false;
    }
  }

  // update the value type
  element->etype = etype;

  // update the rear and front accordingly
  q->front = (q->front == QUEUE_EMPTY ? 0 : q->front);
  q->rear++;

  // finally, add the queue_element to the items array
  q->items[q->rear] = element;

  return true;
}



queue_element* queue_remove(queue *q) {
  if (is_queue_empty(q)) {
    perror("queue_remove(): Queue Underflow");
    return NULL;
  }

  // if this case is true, then there is only element in the queue.
  // after removing it, reset the front and rear to QUEUE_EMPTY
  if (q->front == q->rear) {
    int ref_id = q->rear;

    // reset the front and rear
    q->front = q->rear = QUEUE_EMPTY;

    return q->items[ref_id];
  }

  return q->items[q->front++];
}



const queue_element* queue_peek(const queue *q) {
  if (is_queue_empty(q)) {
    perror("queue_peek(): Queue Underflow");
    return NULL;
  }

  return q->items[q->front];
}



void queue_print(const queue *q) {
  if (is_queue_empty(q)) {
    perror("queue_print(): Queue Underflow");
    return;
  }

  for (int i = q->front; i <= q->rear; i++) {
    // print the index
    printf("%3d", i);

    // print element type and it's value
    switch (q->items[i]->etype) {
      case CHR:
        printf(" %3s %20c \n", "CHR", q->items[i]->value.cval);
        break;
      case INT:
        printf(" %3s %20d \n", "INT", q->items[i]->value.ival);
        break;
      case FLO:
        printf(" %3s %20.3f \n", "FLO", q->items[i]->value.fval);
        break;
      case STR:
        printf(" %3s %20s \n", "STR", q->items[i]->value.sval);
        break;
    }
  }
} 