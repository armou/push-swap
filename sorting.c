#include "linked_list.h"


void split_list(int node) {
    ;
}

void set_pivot(node_list_t* a, node_list_t* b) {
    node_list_t* head;
    node_list_t* tail;
    node_list_t* btail;
    // node_list_t* a;
    // node_list_t* b;
    int pivot;

    head = a;
    pivot = __INT32_MAX__;
    // dprintf(1, "pivot is %d", pivot);
    // a = head;
    // dprintf(1, "debug0");
    while (!list_is_sorted(a) || b != NULL) {
        tail = a;
        while (tail->next) {
            tail = tail->next;
        }
        // dprintf(1, "start of loop\n\n");
        // dprintf(1, "current = %d\n", a->value);
        // dprintf(1,  "next = %d\n", a->next->value);
        // dprintf(1, "prev = %d\n", tail->value);
        if (a->value > a->next->value) {
            // dprintf(1, "debug1");

            swap_node(a);
            printf("sa\n");
        } else if (a->value > tail->value) {
            // dprintf(1, "debug2");
            reverse_rotate_node(&a);
            printf("rra\n");
        } else if (list_is_sorted(a) && b != NULL) {
            // dprintf(1, "debug3");

            if (a->value > b->value) {
                a = push_src_to_dst(&b, a);
                printf("pa\n");
            // } else if (list_is_sorted(b)) {
            //     while (a->value < b->value) {
            //         rotate_node(&a);
            //         printf("ra\n");
            //     }
            //     a = push_src_to_dst(&b, a);
            //     printf("pa\n");
            } else {
                while (a->value < b->value) {
                    rotate_node(&a);
                    printf("ra\n");
                }
                a = push_src_to_dst(&b, a);
                printf("pa\n");
                // if (b->next != NULL) {
                //     btail = b;
                //     while (btail->next)
                //         btail = btail->next;
                //     dprintf(1, "debug9");
                //     if (b->next->value > btail->value && b->next->value < b->value) {
                //         swap_node(b);
                //         printf("sb\n");
                //     } else if (b->next->value < btail->value && btail->value < b->value) {

                //                                 rotate_node(&b);
                //         printf("rb\n");
                //     } else {
                //         dprintf(1, "debug10");
                //     }
                // }
            }
        } else {
            // dprintf(1, "debug4");

            b = push_src_to_dst(&a, b);
            // if (b->value < pivot)
            //     pivot = b->value;
            printf("pb\n");
            // dprintf(1, "debug7");
            if (b->next != NULL) {
                btail = b;
                while (btail->next)
                    btail = btail->next;
                // dprintf(1, "debug6");

                if (b->next->value > btail->value && b->next->value < b->value) {
                    swap_node(b);
                    printf("sb\n");
                } else if (b->next->value < btail->value && btail->value < b->value) {

                                        rotate_node(&b);
                    printf("rb\n");
                }
            }
        }
        // printf("Print List A\n");
        // print_list(a);
        // printf("Print List B\n");
        // print_list(b);
    }
    printf("-- list is sorted --");

}


void ft_putchar(char s){
    write(1, &s, 1);
}

// int main(void) {
//     ft_putchar(50);
// }