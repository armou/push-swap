#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



typedef struct node_list {
    int value;
    int index;
    int isHead;
    struct node_list* next;
    struct node_list* prev;

} node_list_t;

int list_is_sorted(node_list_t* current);
void ft_putchar(char s);
void set_pivot(node_list_t* a, node_list_t* b);
void swap_node(node_list_t* head);
node_list_t* push_src_to_dst(node_list_t** src, node_list_t* dst);
void reverse_rotate_node(node_list_t** head);
void rotate_node(node_list_t** head);
void print_list(node_list_t* head);


#endif