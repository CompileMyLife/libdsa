#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

#define ARRAY_SIZE(EXPR) sizeof(EXPR)/sizeof(EXPR[0])

void printInt(void *num);
void printFloat(void *f);    
void printChar(void *c);

int main(void){
    // Create lists
    sllNode_t *ll_1 = sll_create();
    sllNode_t *ll = sll_create();
    sllNode_t *char_ll = sll_create();

    // Get len of empty list
    printf("%d\n", sll_len(ll));

    // Print an empty list with specified func for data type
    sll_printls(ll, printInt);
    
    // Check if linked list is empty
    printf("Empty: %d\n", sll_isEmpty(ll));

    // Sample arrays of data
    int arr[] = {0, 10, 20, 30, 40, 50};
    float f_arr[] = {0.0, 9.0, 8.7, 11.0, 83.0, 40.9, 95.8};
    char c_arr[] = {'a', 'b', 'c', 'd', 'e'};

    // Sample variables of data
    int b = 10000;
    float c = 1000.0;
    char ch = 'f';

    // insert if list is empty
    sll_insert(&ll, &c, 1);

    // Pushing/Inserting Data
    for (int i = 0; i < ARRAY_SIZE(arr); i++) {
        sll_pushf(&ll_1, &arr[i]);
    }
    
    for (int i = 0; i < ARRAY_SIZE(f_arr); i++) {
        sll_pushb(&ll, &f_arr[i]);
    }

    for (int i = 0; i < ARRAY_SIZE(c_arr); i++) {
        sll_pushf(&char_ll, &c_arr[i]); 
    }

    // Popping data
    float a = *(float*)sll_popb(&ll);
    printf("%f\n", a);

    // Push using address of variables
    sll_pushb(&ll, &a);
    sll_pushf(&ll_1, &b); 
    sll_insert(&char_ll, &ch, 0); 

    // Print out length of lists
    printf("%d\n", sll_len(ll_1));
    printf("%d\n", sll_len(ll));
    printf("%d\n", sll_len(char_ll));
    
    // Print list to stdout w/ user created data type functions 
    sll_printls(ll_1, printInt);
    sll_printls(ll, printFloat);
    sll_printls(char_ll, printChar);

    // Delete a particular node
    sll_del(&ll_1, 3);
    sll_printls(ll_1, printInt);


    // Delete lists
    sll_free(&ll_1);
    sll_free(&ll);
    sll_free(&char_ll);
    
    return 0;
}

// Functions to cast values in SLL
// to their repsective types
void printInt(void *num) {
    printf(" %d\n", *(int *)num);
}

void printFloat(void *f) {
    printf(" %.2f\n", *(float *)f);
}

void printChar(void *c) {
    printf(" %c\n", *(char *)c);
}
