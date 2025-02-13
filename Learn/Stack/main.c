#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>'

#define SIZE(stack) ((stack)->size)

// Stack data structure definition.  An array is used to implement a stack, 
// it is possible to implement stacks in other ways (e.g. a linked list).  The
// 0th index becomes the "bottom" of the stack, and we "stack" items at each 
// subsequent index in the array.
typedef struct
{
  // pointer to dynamically allocated array which will store stack items
  int *collection;
  
  // the length of the collections array is the max capacity of items
  int capacity;

  // the current number of items in the stack
  int size;

} Stack;

Stack *create_stack(int capacity);
void destroy_stack(Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item);
void print_stack(Stack *stack);


int main() {
    Stack *card = create_stack(10);

    for (int i = 0; i < 10; i++) {
        push(card, i);
    }

    print_stack(card);

    printf("Stack size: %d\n", card->size);
}

Stack *create_stack(int capacity) {
      // Don't allow stacks with a capacity <= 0
  if (capacity <= 0) return NULL;
  
  // allocate space for the stack on the heap, return NULL if malloc fails
  Stack *stack = malloc(sizeof(Stack));
  if (stack == NULL) return NULL;
  
  // allocate enough space to store capacity number of items in collections
  stack->collection = malloc(sizeof(int) * capacity);

  // if the allocation of space for collection fails, we'll need to free the 
  // stack allocated on the heap before returning NULL to prevent a memory leak
  if (stack->collection == NULL)
  {
    free(stack);
    return NULL;
  }
  
  // set the capacity to the provided capacity, and the initialize size is zero
  stack->capacity = capacity;
  stack->size = 0; //(*stack).size = 0; sama aja
  
  // return the pointer to the Stack on the heap
  return stack;
}

bool push(Stack *stack, int item){
      // We cannot push an item onto the stack if it is full, so return false if so
  
  // set the next available index in the collection array to the item 
  stack->collection[stack->size] = item;

  // increment the size of the stack (if another item is pushed to the stack 
  // immediately after this, it will be stored in the NEXT array index)
  stack->size++;
  
  // return true as we have successfully pushed an item onto the stack
  return true;
}

void print_stack(Stack *stack) {
  for (int i = 0; i < stack->size; i++) {
    printf("%d ", stack->collection[i]);
  }
  printf("\n");
}
