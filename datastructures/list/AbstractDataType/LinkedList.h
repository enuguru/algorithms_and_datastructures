
typedef struct linkedlist *LinkedList;

LinkedList listInit(int maxSize); 

void listEmpty(LinkedList);

int emptyList(LinkedList); 

void insertNext(LinkedList, int); 

int removeNode(LinkedList); 

void traverseAndPrintList(LinkedList); 

void first(LinkedList); 

void last(LinkedList); 

void setNode(LinkedList, int);

int getNode(LinkedList);                          
