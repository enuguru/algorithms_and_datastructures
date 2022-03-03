

// Arup Guha
// 2/27/08
// Example of a heap data structure implementation for COP 3502

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100

struct heapStruct {

    int* heaparray;
    int capacity;
    int size;
};

struct heapStruct *initHeap();
struct heapStruct * initHeapfromArray(int* values, int length);
void heapify(struct heapStruct *h);
void percolateDown(struct heapStruct *h, int index);
void percolateUp(struct heapStruct *h, int index);
void insert(struct heapStruct *h, int value);
int removeMin(struct heapStruct *h);
void printHeap(struct heapStruct *h);
void swap(struct heapStruct *h, int index1, int index2);
int minimum(int a, int indexa, int b, int indexb);
void freeHeap(struct heapStruct *h);

void sort(int values[], int length);

int main() {

    int i;
    int vals[10];
    struct heapStruct *h;
    h = initHeap();

    // Test out individual inserts.
    insert(h, 7);
    insert(h, 3);
    insert(h, 5);
    insert(h, 12);
    insert(h, 2);
    insert(h, 8);
    insert(h, 4);
    insert(h, 9);
    insert(h, 1);
    printHeap(h);

    for (i=0; i<9; i++) {
        printf("Delete %d\n",removeMin(h));
        printHeap(h);
    }
    freeHeap(h);
    
    // Test out array initialization.
    vals[0] = 12, vals[1] = 3, vals[2] = 18, vals[3] = 14, vals[4] = 5;
    vals[5] = 9, vals[6] = 1, vals[7] = 7; vals[8] = 2, vals[9] = 13;
    
    sort(vals, 10);
    
    for (i=0; i<10; i++)
        printf("%d ", vals[i]);
    printf("\n");
    
    system("PAUSE");
    return 0;
}

// Initialize an empty heap with a capacity of SIZE.
struct heapStruct* initHeap() {

    struct heapStruct* h;
    
    // Allocate space for the heap and set the size for an empty heap.
    h = (struct heapStruct*)(malloc(sizeof(struct heapStruct)));
    h->capacity = SIZE;
    h->heaparray = (int*)malloc(sizeof(int)*(SIZE+1));
    h->size = 0;
    return h;
}

// Frees the struct pointed to by h.
void freeHeap(struct heapStruct *h) {
     free(h->heaparray);     
     free(h);
}

// Initializes the heap using the first length number of items in the array
// values.
struct heapStruct * initHeapfromArray(int* values, int length) {
     
    int i;
    struct heapStruct* h;
    
    h = (struct heapStruct*)(malloc(sizeof(struct heapStruct)));
    // We allocate one extra slot, since slot 0 stays unused. 
    h->heaparray = (int*)malloc(sizeof(int)*(length+1));
    
    // Just copy the values into our array.
    for (i=1; i<=length; i++)
        h->heaparray[i] = values[i-1];
      
    // This is the number of values we copied.
    h->size = length;
    
    // This takes our random values and rearranges them into a heap.
    heapify(h);
    return h;
}

// h points to a heap structure that has values inside of it, but isn't yet
// organized into a heap and does exactly that.
void heapify(struct heapStruct *h) {
     
    int i;
     
    // We form a heap by just running percolateDown on the first half of the 
    // elements, in reverse order.
    for (i=h->size/2; i>0; i--) 
        percolateDown(h, i);
    
}

// Runs percolate down on the heap pointed to by h on the node stored in index.
void percolateDown(struct heapStruct *h, int index) {

    int min;
    
    // Only try to percolate down internal nodes.
    if ((2*index+1) <= h->size) {
                    
        // Find the minimum value of the two children of this node.            
        min = minimum(h->heaparray[2*index], 2*index, h->heaparray[2*index+1], 2*index+1);
        
      // If this value is less than the current value, then we need to move
      // our current value down the heap.  
        if (h->heaparray[index] > h->heaparray[min]) {
            swap(h, index, min);
        
            // This part is recursive and allows us to continue percolating
            // down the element in question.
            percolateDown(h, min);
        }
    }
    
    // Case where our current element has exactly one child, a left child.
    else if (h->size == 2*index) {
         
        // Here we only compare the current item to its only child.
        // Clearly, no recursive call is needed since the child of this node
        // is a leaf. 
        if (h->heaparray[index] > h->heaparray[2*index]) 
            swap(h, index, 2*index);
    }
  }

// Runs percolate up on the heap pointed to by h on the node stored in index.
void percolateUp(struct heapStruct *h, int index) {

    // Can only percolate up if the node isn't the root.
    if (index > 1) {
              
        // See if our current node is smaller in value than its parent.        
        if (h->heaparray[index/2] > h->heaparray[index]) {
            
            // Move our node up one level.
            swap(h, index, index/2);
            
            // See if it needs to be done again.
            percolateUp(h, index/2);
        }
    }
}

// Inserts value into the heap pointed to by h.
void insert(struct heapStruct *h, int value) {

    int* temp;
    int* throwaway;
    int i;
    
    // Our array is full, we need to allocate some new space!
    if (h->size == h->capacity) {
                
        // We will double the size of the structure.
        h->capacity *= 2;
      
        // Allocate new space for an array.
        temp = (int*)malloc(sizeof(int)*h->capacity+1);
      
        // Copy all the items over.
        for (i=1; i<=h->capacity; i++)
            temp[i] = h->heaparray[i];
            
        // Move the pointer and free the old memory.
        throwaway = h->heaparray;
        h->heaparray = temp;
        free(throwaway);
    }
      
    // Adjust all the necessary components of h, and then move the inserted
    // item into its appropriate location.  
    h->size++;
    h->heaparray[h->size] = value;
    percolateUp(h, h->size);
}

int removeMin(struct heapStruct *h) {

    int retval;
    
    // We can only remove an element, if one exists in the heap!
    if (h->size > 0) {

        // This is where the minimum is stored.
        retval = h->heaparray[1];
        
        // Copy the last value into this top slot.
        h->heaparray[1] = h->heaparray[h->size];
        
        // Our heap will have one fewer items.
        h->size--;
        
        // Need to let this value move down to its rightful spot in the heap.
        percolateDown(h, 1);
        
        // Now we can return our value.
        return retval;
    }
    
    // No value to return, indicate failure with a -1.
    else
        return -1;
}

// For debugging purposes, lets us see what's in the heap.  
void printHeap(struct heapStruct *h) {
    int i;
    
    for (i=1; i<=h->size; i++)
        printf("%d ", h->heaparray[i]);
    printf("\n");
}

// Swaps the values stored in the heap pointed to by h in index1 and index2.
void swap(struct heapStruct *h, int index1, int index2) {
    int temp = h->heaparray[index1];
    h->heaparray[index1] = h->heaparray[index2];
    h->heaparray[index2] = temp;
}

// Returns indexa if a < b, and returns indexb otherwise.
int minimum(int a, int indexa, int b, int indexb) {

    // Return the value associated with a.    
    if (a < b)
        return indexa;
        
    // Return the value associated with b.
    else
        return indexb;
}

// Runs a heap sort by creating a heap out of the values in the array, and then
// extracting those values one-by-one from the heap back into the array in the
// proper order.
void sort(int values[], int length) {

     struct heapStruct *h;
     int i;
     
     // Create a heap from the array of values.
     h =  initHeapfromArray(values, length);
     length = h->size;
     
     // Remove these values from the heap one by one and store them back in the 
     // original array.
     for (i=0; i<length; i++) {
         values[i] = removeMin(h);
     }
}



