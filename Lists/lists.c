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

#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

// Generic Linked List:
typedef struct sllnode {
    void *data;         // any data type 
    struct sllnode *next; // pointer to next node
} sllNode_t;

// Create the linked list
// then return linked list to user
sllNode_t *sll_create(void){

    // Initialize the head to NULL
    sllNode_t *head = NULL;
    return head;
}

// Free the linked list from ptr-->ptr--> HeadNode
void sll_free(sllNode_t **head){
    
    sllNode_t *cur, *next;

    // current node point to head node
    cur = *head;

    // Traverse the list until cur == NULL
    while (cur != NULL) {
        // Next node is current's next
        next = cur->next;
        free(cur);
        // Let current node be next node
        cur = next;
    }

    *head = NULL;
    fprintf(stdout, "SLL type freed\n");
}

void sll_insert(sllNode_t **head, void *new_data, unsigned int n){
    // Let current node point to pointer to head node
    sllNode_t *cur = *head;
        
    // Allocate mem for new_node
    sllNode_t *new_node = (sllNode_t *)malloc(sizeof(sllNode_t));

    // Check if new_node allocated successfully
    if (new_node == NULL){ 
        fprintf(stderr, 
                "sll_insert: Failed to allocate memory for new node to be inserted in SLL\n"); 
        return;
    }

    new_node->data = new_data;
    // Assign new_node's next to NULL temporarily
    new_node->next = NULL;

    // Check if head of linked list is NULL ie. (List is empty)
    // and if index is 0
    if (cur == NULL && n == 0) { 
        // Point new_node's next to head
        new_node->next = *head;

        // Point head to new_node
        *head = new_node;
        return;
    }
    
    // Check if the index is greater than length of sll
    // or index is less than 0 or SLL empty and 
    // index is greater than 0
    if ((n > sll_len(*head) - 1) || (n < 0) || (*head == NULL && n > 0)){
        fprintf(stderr,"sll_insert: index out of range of SLL\n");

        free(new_node);
        return;
    }

    for (int i = 0; cur != NULL && i <= n; i++){
        if (i == n){
            // Point new_node's next to current's next
            new_node->next = cur->next;

            // Point current's next to new_node
            cur->next = new_node;
        }
        else {
            // Traverse to next node in SLL
            cur = cur->next;
        }
    }
}

void sll_pushf(sllNode_t **head, void *new_data){
    
    // Allocate mem for newnode
    sllNode_t *new_node = (sllNode_t*)malloc(sizeof(sllNode_t)); 

    // Check if allocation for newnode is successful
    if (new_node == NULL){
        fprintf(stderr,
                "sll_pushf: Failed to allocate mem for newnode to be pushed at front of SLL\n");
        return;
    }

    // Set data and set newnode.next temporarily to NULL
    new_node->data = new_data;
    new_node->next = NULL;

    // Check if List is empty then set newnode as head node
    if (*head == NULL){
        *head = new_node;
        (*head)->data = new_data;
        (*head)->next = NULL;
    }

    // ELSE set newnode.next to where head currently 
    // is pointing then set head to newnode
    else {
        new_node->next = *head;
        *head = new_node;
    }
}

void sll_pushb(sllNode_t **head, void *new_data){
    sllNode_t *temp, *cur;
    
    // Allocate mem for node
    temp = (sllNode_t*)malloc(sizeof(sllNode_t));

    // Check if temp node allocated successfully
    if (temp == NULL){
        fprintf(stderr,
                "sll_pushb: Failed to allocate mem for new node to be pushed node at back of SLL\n");
        return;
    }

    // set data and temp.next temporarily to NULL
    temp->data = new_data;
    temp->next = NULL;

    // Point cur node to head
    cur = *head;

    // Check if cur is NULL (Empty List)
    // then set temp to head
    if(cur == NULL){
        *head = temp;
    }

    // ELSE traverse list till cur is not NULL
    // then set cur.next to temp node
    else {
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
}

void *sll_popf(sllNode_t **head){ 
    // Check if list is Empty
    if (*head == NULL){
        fprintf(stderr,"sll_popf: SLL type list is Empty\n");
        return NULL;
    }

    // Point temp node to head
    sllNode_t *temp = *head;
    
    // Set data to temp->data
    void *data = temp->data;

    // Point head to head's next node
    *head = (*head)->next;

    free(temp);
    return(data);
}

void *sll_popb(sllNode_t **head){
    // Check if list is empty 
    if (*head == NULL) {
        fprintf(stderr,"sll_popb: SLL type list is empty\n");
        return NULL;
    }

    // Set temp node to NULL temporarily
    sllNode_t *temp = NULL;

    // Point cur node to head node
    sllNode_t *cur = *head;

    // Traverse list till NULL and set temp node to cur node
    while(cur->next){
        temp = cur;
        cur = cur->next;
    }

    // Set temp.next to NULL
    temp->next = NULL;
    // Save data from cur node
    void *data = cur->data;

    free(cur);
    return(data);
}

int sll_isEmpty(sllNode_t *head){
    // Check if SLL is empty
    // and return 1 if true;
    if (head == NULL){
        return 1;
    }

    else {
        return 0;
    }
}

int sll_len(sllNode_t *head){
    // Point cur node to head node
    sllNode_t *cur = head;

    int count = 0;

    // Traverse list and increment count per node till NULL
    while (cur != NULL){
        count++;
        cur = cur->next;
    }

    return count;
}

void sll_printls(sllNode_t *head, void (*func_ptr)(void *)){
    // Point cur node to head node
    sllNode_t *cur = head;

    int i = 0;
    // Traverse list and use function specified by user 
    // to print out data till NULL
    while (cur != NULL){
        printf("SLL(%d) = ", i);
        (*func_ptr)(cur->data);
        cur = cur->next;
        i++;
    }
    printf("\n");
}

void sll_del(sllNode_t **head, unsigned int n){
    // Point prev and cur to head
    sllNode_t *prev = *head; 
    sllNode_t *cur = *head;

    // Check if list is empty
    if(*head == NULL){
       fprintf(stderr, "sll_del: SLL type list is empty\n");
       return;
    }

    else if (n > (sll_len(*head) - 1)){
        fprintf(stderr, "sll_del: index searched for is out of range\n");

        return;
    }

    // Check if index is 0
    else if(n == 0){
        // Set head node's next node to current node
        *head = (*head)->next;
        
        // Delete/Free the prev node since it was pointing
        // to old head node
        free(prev);
        prev->next = NULL;
    }

    // Check if index is 1
    else if(n == 1){
        // Point head node to current's next node
        *head = cur->next;
        free(cur);
        cur = NULL;
    }
    else {

        // Traverse list till index is not 0
        while(n != 0){
            // Point previous to current
            prev = cur;
            // Point current to current's next
            cur = cur->next;
            n--;
        }
        // Set previous's next node to current's next node
        prev->next = cur->next;
        free(cur);
        cur = NULL;
    }
}
