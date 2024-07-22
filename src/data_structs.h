#include <stdlib.h>

typedef struct Node {
    double value;
    int index;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct List {
    int len;
    Node *first;
    Node *last;
} List;