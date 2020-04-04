#include "linked_list.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void print_list(node_list_t* head) {
    node_list_t* print_list;

    print_list = head;
    // printf("attempting print\n");
    while (print_list != NULL) {
        printf("This list value is : %d\n", print_list->value);
        print_list = print_list->next;
    }
}


node_list_t* push_list(node_list_t* head, int value) {
    node_list_t* current;

    current = NULL;
    if (head) {
        current = head;
        // current->isHead = 0;
        if (!(current->next = (node_list_t*)malloc(sizeof(node_list_t)))) {
            ;
        }
        current->next->value = value;
        current->next->index = current->index++;
        current->next->prev = current;
        current->next->isHead = 0;
        // if (final == 1) {prev
        //     current->prev->isHead = 1;
        // }
        current = current->next;
    }
    return current;
    // head->prev = current;
    // print_list(current);
}

node_list_t* push_list_reverse(node_list_t* head, int value, int final) {
    node_list_t* current;

    current = NULL;
    if (head) {
        current = head;
        current->isHead = 0;
        if (!(current->prev = (node_list_t*)malloc(sizeof(node_list_t)))) {
            ;
        }
        current->prev->value = value;
        // current->prev->index = current->index - 1;
        current->prev->next = current;
        current->prev->isHead = 0;
        // value--;
        if (final == 1) {
            current->prev->isHead = 1;
        }
        current = current->prev;
    }
    return current;
    // head->prev = current;
    // print_list(current);
}

void swap_node(node_list_t* head){
    node_list_t* current;
    int             tmp;
    printf("--- Swapping values ---\n");
    current = head;

    if (current && current->next) {
        tmp = current->value;
        current->value = current->next->value;
        current->next->value = tmp;
    }
}


void rotate_node(node_list_t* head){
    node_list_t* current;
    int             tmp;

    printf("--- Rotating values ---\n");
    current = head;
    if (current && current->next) {
        while (current && current->next) {
            tmp = current->value;
            current->value = current->next->value;
            current = current->next;
        }
        current->value = tmp;
    }
}

void reverse_rotate_node(node_list_t* head) {
    node_list_t* current;
    int             tmp;

    printf("--- Reverse Rotating values ---\n");
    current = head;
    if (current) {
        while (current->next) {
            current = current->next;
        }
        tmp = current->value;
        while (current->prev) {
            current->value = current->prev->value;
            current = current->prev;
        }
        head->value = tmp;
    }
}

node_list_t* push_src_to_dst(node_list_t** src, node_list_t* dst) {
    node_list_t* current;
    node_list_t* tmp;

    tmp = NULL;
    // printf("Our node index is : %d\nOur node value is : %d\n", (*src)->index, (*src)->value);
    if ((*src)) {
        printf("--- Pushing value from list A to list B ---\n");
        if (!(current = (node_list_t*)malloc(sizeof(node_list_t)))) {
            printf("malloc error\n");
        }
        current->value = (*src)->value;
        tmp = (*src);
        // (*src)->next->prev = NULL;
        while ((*src)->next != NULL) {
            (*src)->next->index--;
            (*src)->next->isHead = 1;
            (*src) = (*src)->next;
        }
        if (tmp->next) {
            // dprintf(1, "debug1\n");
            (*src) = tmp->next;
        } else {
            // printf("debug2\n");
            (*src) = NULL;
        }
        free(tmp);

        current->isHead = 1;
        current->index = 0;
        current->prev = NULL;
        if (dst != NULL) {
            current->next = dst;
            dst->prev = current;
            while (dst->next) {
                dst->isHead = 0;
                dst->index++;
                dst = dst->next;
            }
        }
        return current;
    } else {
        printf("--- Cannot push value because SRC is empty ---\n");
        return dst;
    }
    // printf("Our node index is : %d\nOur node value is : %d\n", (*src)->index, (*src)->value);
}

int list_is_sorted(node_list_t* head) {
    node_list_t* current;

    current = head;
    while (current->next) {
        if(current->next->value < current->value) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

void init_list() {
    node_list_t* head;
    node_list_t* list_a;
    node_list_t* list_b;

    head = NULL;
    list_b = NULL;
    if (!(head = (node_list_t*)malloc(sizeof(node_list_t)))) {
        // return 1;
    }
    head->index = 0;
    head->value = 1;
    head->isHead = 1;
    head->next = NULL;
    head->prev = NULL;
    printf("Our node index is : %d\nOur node value is : %d\n", head->index, head->value);
    push_list(head, 10);
    print_list(head);
    swap_node(head);
    print_list(head);
    rotate_node(head);
    print_list(head);
    reverse_rotate_node(head);
    print_list(head);
    list_b = push_src_to_dst(&head, list_b);
    list_b = push_src_to_dst(&head, list_b);
    list_b = push_src_to_dst(&head, list_b);
    list_b = push_src_to_dst(&head, list_b);
    printf("print list A\n");
    // printf("Our node index is : %d\nOur node value is : %d\n", head->index, head->value);
    print_list(head);
    printf("print list B\n");
    print_list(list_b);
    // return 0;
}

void init_linked_list(node_list_t** a) {
    if (!((*a) = (node_list_t*)malloc(sizeof(node_list_t)))) {
        ;
        // return 1;
    }

    (*a)->isHead = 1;
    (*a)->index = 0;
    (*a)->prev = NULL;
    (*a)->next = NULL;

}

int read_and_check(node_list_t* a, node_list_t* b) {
    while (1) {
        char s[100];
        fgets( s, 10, stdin);
        printf("\n\n --- NEW COMMAND ---\n");
        printf("input value is %s\n", s);
        // printf("length of s is %d\n", strlen(s));
        if (strncmp(s, "sa", 2) == 0 && strlen(s) == 3) {
            printf("sa command detected\n");
            swap_node(a);
        } else if (strncmp(s, "sb", 2) == 0 && strlen(s) == 3) {
            printf("sb command detected\n");
            swap_node(b);
        } else if (strncmp(s, "pa", 2) == 0 && strlen(s) == 3) {
            printf("pa command detected\n");
            a = push_src_to_dst(&b, a);
        } else if (strncmp(s, "pb", 2) == 0 && strlen(s) == 3) {
            printf("pb command detected\n");
            b = push_src_to_dst(&a, b);
        } else if (strncmp(s, "ss", 2) == 0 && strlen(s) == 3) {
            printf("ss command detected\n");
            swap_node(a);
            swap_node(b);
        } else if (strncmp(s, "ra", 2) == 0 && strlen(s) == 3) {
            printf("ra command detected\n");
            rotate_node(a);
        } else if (strncmp(s, "rb", 2) == 0 && strlen(s) == 3) {
            printf("rb command detected\n");
            rotate_node(b);
        } else if (strncmp(s, "rr", 2) == 0 && strlen(s) == 3) {
            printf("rr command detected\n");
            rotate_node(a);
            rotate_node(b);
        } else if (strncmp(s, "rra", 3) == 0 && strlen(s) == 4) {
            printf("rra command detected\n");
            reverse_rotate_node(a);
        } else if (strncmp(s, "rrb", 3) == 0 && strlen(s) == 4) {
            printf("rrb command detected\n");
            reverse_rotate_node(b);
        } else if (strncmp(s, "rrr", 3) == 0 && strlen(s) == 4) {
            printf("rrr command detected\n");
            reverse_rotate_node(a);
            reverse_rotate_node(b);
        }
        printf("Print List A\n");
        print_list(a);
        printf("Print List B\n");
        print_list(b);
    }
     
}

int main(int argc, char **argv) {
    int i;
    node_list_t* tail;
    node_list_t* head;
    node_list_t* swap;

    i = 1;
    tail = NULL;
    head = NULL;
    swap = NULL;
    if (argc < 2)
        return 0;
    init_linked_list(&tail);
    tail->value = atoi(argv[i++]);
    // init_linked_list(&swap);
    
    head = tail;
    print_list(tail);
    while (argv[i]) {
        printf("argument %d = %d\n", i, atoi(argv[i]));
        // head = push_list_reverse(head, atoi(argv[i]), i == argc - 1 ? 1 : 0);
        tail = push_list(tail, atoi(argv[i]));
        i++;
    }
    print_list(head);
    read_and_check(head, swap);
    // print_list(tail);
    return 0;
}