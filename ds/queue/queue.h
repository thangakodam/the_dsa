#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// data types to be used with queue
#define CHR  1
#define INT  2 
#define FLO  3
#define STR  4

#define QUEUE_EMPTY   -1      // -1 represents the queue is empty
#define QUEUE_SIZE    100


/* struct represents each element of queue */
typedef struct {
  int etype;

  union {
    char cval;
    int ival;
    double fval;
    char *sval;
  }value;

} queue_element;

/* struct represents the queue */
typedef struct {
  int front;             // where elements are removed
  int rear;              // where elements are inserted
  queue_element **items; 
} queue;


/********** OPERATIONS ON QUEUE **********/
/**
 * Initialize queue and return the reference.
 * 
 * @return Pointer to 'queue' struct else NULL
 */
queue* Queue(void);

/**
 * Is queue empty ?
 * 
 * @return True if queue is empty else False
 */
bool is_queue_empty(const queue *);

/**
 * Is queue full ?
 * 
 * @return True if queue is full else False
 */
bool is_queue_full(const queue *);

/**
 * Get no of elements in the queue.
 * 
 * @param[in] queue: Pointer to queue struct
 * @return Returns the items count in the queue.
 */
int queue_size(const queue *);

/**
 * Insert element to queue at the bottom side.
 * 
 * @param[in] queue: Pointer to queue struct.
 * @param[in] int: Value type, either CHR, INT, FLO, STR.
 * @param[in] void*: Pointer to the data value
 * @return Bool value denoting if the insertion is success or not
 */
bool queue_insert(queue *, int, void *);

/**
 * Remove the element from top of queue and returns it.
 * 
 * @param[in] queue: Pointer to queue struct.
 * @return Pointer to top queue_element.
 */
queue_element* queue_remove(queue *);

/**
 * Peek, to take a look at the front element of queue.
 * 
 * @param[in] queue*: pointer to the queue struct
 * @return Returns a pointer to the queue_element struct
 */
const queue_element* queue_peek(const queue *);

/**
 * Print all the elements of queue from front to rear
 * 
 * @param[in] queue*: Pointer to queue struct
 */
void queue_print(const queue *);