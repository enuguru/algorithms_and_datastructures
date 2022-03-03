

#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

#define SENTINEL_VAL 9001
#define WAIT_SEC 10

typedef struct {
	int *data;
	int heapSize;
	int arrSize;
} HEAP;

static HEAP* myHeap;
static int heapHeight = 0;

void displayChildren(int);
void createHeap(void);
void insertVal(void);
void percolateUp(int);
void deleteMin(void);
void percolateDown(int);
void swap(int, int);
int getMin(void);
int getParentIndex(int);
int getLeftChildIndex(int);
int getRightChildIndex(int);

int main() {
	createHeap();
	do {
		insertVal();
		printf("\n");
		if (myHeap->data[myHeap->heapSize - 1] == SENTINEL_VAL)
			--myHeap->heapSize;
		displayChildren(0);
		printf("\n");
	} while (myHeap->data[myHeap->heapSize] != SENTINEL_VAL);
	printf("Final Binary Heap:\n");
	displayChildren(0);

	printf("\nExiting in %d seconds...\n", WAIT_SEC);
	//Sleep(WAIT_SEC*1000);

	return 0;
}

void displayChildren(int index) {
	int i, leftChildIndex, rightChildIndex;

	leftChildIndex = getLeftChildIndex(index);
	rightChildIndex = getRightChildIndex(index);

	for (i = 0; i < heapHeight; ++i)
		printf("..");
	printf("%d\n", myHeap->data[index]);
	if (index < myHeap->heapSize) {
		if (leftChildIndex >= myHeap->heapSize
			&& rightChildIndex >= myHeap->heapSize)
			return;
		++heapHeight;
		if (leftChildIndex < myHeap->heapSize)
			displayChildren(leftChildIndex);
		if (rightChildIndex < myHeap->heapSize)
			displayChildren(rightChildIndex);
		--heapHeight;
	}
}

void createHeap(void) {
	int arrSize;

	do {
		printf("Input the maximum heap size: ");
		scanf("%d", &arrSize);
		if (arrSize <= 0)
			printf("Maximum heap size must be a positive value!\n");
		printf("\n");
	} while (arrSize <= 0);

	myHeap = (HEAP*)malloc(sizeof(HEAP));
	myHeap->data = (int*)malloc(sizeof(int) * arrSize + 1);
	myHeap->heapSize = 0;
	myHeap->arrSize = arrSize;
}

void insertVal(void) {
	int val;

	printf("Input the value you wish to insert (%d to exit): ", SENTINEL_VAL);
	scanf("%d", &val);

	if (myHeap->heapSize == myHeap->arrSize) {
		printf("Operation failed! Heap space exhausted!\n");
	} else {
		myHeap->data[myHeap->heapSize] = val;
		percolateUp(myHeap->heapSize);
		++myHeap->heapSize;
	}
}

void percolateUp(int index) {
	int parentIndex;

	if (myHeap && myHeap->heapSize > 0 && index > 0) {
		parentIndex = getParentIndex(index);
		if (myHeap->data[parentIndex] > myHeap->data[index]) {
			swap(parentIndex, index);
			percolateUp(parentIndex);
		}
	}
}

void deleteMin(void) {
	if (myHeap && myHeap->heapSize > 0) {
		myHeap->data[0] = myHeap->data[myHeap->heapSize - 1];
		--myHeap->heapSize;
		percolateDown(0);
	} else {
		printf("Operation Failed! Heap is Empty!\n");
	}
}

void percolateDown(int index) {
	int leftChildIndex, rightChildIndex, smallIndex;

	leftChildIndex = getLeftChildIndex(index);
	rightChildIndex = getRightChildIndex(index);

	if (rightChildIndex >= myHeap->heapSize
		&& leftChildIndex >= myHeap->heapSize)
		return;
	else if (rightChildIndex >= myHeap->heapSize) {
		smallIndex = leftChildIndex;
	} else {
		smallIndex = myHeap->data[leftChildIndex] <=
			myHeap->data[rightChildIndex] ?
			leftChildIndex : rightChildIndex;
	}

	if (myHeap->data[index] > myHeap->data[smallIndex]) {
		swap(index, smallIndex);
		percolateDown(smallIndex);
	}
}

void swap(int parentIndex, int index) {
	int tempVal;

	tempVal = myHeap->data[parentIndex];
	myHeap->data[parentIndex] = myHeap->data[index];
	myHeap->data[index] = tempVal;
}

int getMin(void) {
	return myHeap->data[0];
}

int getParentIndex(int index) {
	return (index - 1) / 2;
}

int getLeftChildIndex(int index) {
	return 2 * index + 1;
}

int getRightChildIndex(int index) {
	return 2 * index + 2;
}
