#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node_list {
    int value;
    int index;
    int isHead;
    struct node_list* next;
    struct node_list* prev;

} node_list_t;

#endif