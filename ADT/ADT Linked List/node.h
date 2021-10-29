#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef int ElTypeLinked;
typedef struct node* Address;
typedef struct node {
    ElTypeLinked info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElTypeLinked val);


#endif
