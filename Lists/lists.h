/* Author: CompileMyLife
 * Date: 9-25-2022
 * 
 * NOTE: This singly linked list was inspired from the book "Data Structure 
 * and Algorithms Made Easy" by Narasimha Karumanchi. My goal was to create a
 * generic singly linked list to be used for any data type. It still needs
 * improvement. I would like to get some feedback and maybe pointers to a
 * better solution.
 *
 */

#ifndef LISTS_H
#define LISTS_H

typedef struct sllnode sllNode_t;

// Creates a linked list
// then returns newly created linked list
sllNode_t *sll_create(void);

// Delete/Free the linked list
void sll_free(sllNode_t **head);

// Insert a node in linked list at index n
void sll_insert(sllNode_t **head, void* new_data, unsigned int n);

// Push a node to front of linked list with input data
void sll_pushf(sllNode_t **head, void *new_data);

// Push a node to back of linked list with input data
void sll_pushb(sllNode_t **head, void *new_data);

// Pop a node from front of linked list
// then returns data from front popped node
void *sll_popf(sllNode_t **head);

// Pop a node from back of linked list
// then returns data from back popped node
void *sll_popb(sllNode_t **head);

// Check if linked list is empty
// returns 1 if true or 0 if false
int sll_isEmpty(sllNode_t *head);

// Length of the linked list
int sll_len(sllNode_t *head);

// Print linked list and user needs to specify a function
// for printing the type of data present in linked list
void sll_printls(sllNode_t *head, void (*func_ptr)(void *));

// Delete a node from linked list at index n
void sll_del(sllNode_t **head, unsigned int n);

#endif
