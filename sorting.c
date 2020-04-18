#include "linked_list.h"


void split_list(int node) {
    ;
}

void set_pivot(node_list_t* a, node_list_t* b) {
    node_list_t* head;
    // node_list_t* a;
    // node_list_t* b;
    int pivot;

    head = a;
    // a = head;
    // dprintf(1, "debug0");
    while (!list_is_sorted(a) || b != NULL) {
        dprintf(1, "start of loop\n\n");
        dprintf(1, "current = %d\n", a->value);
        dprintf(1,  "next = %d\n", a->next->value);
        dprintf(1, "prev = %d\n", a->prev->value);
        if (a->value > a->next->value) {
            // dprintf(1, "debug1");

            swap_node(a);
            printf("sa\n");
        //             dprintf(1, "current = %d\n", a->value);
        // dprintf(1,  "next = %d\n", a->next->value);
        // dprintf(1, "prev = %d\n", a->prev->value);
        } else if (a->value > a->prev->value) {
        //     dprintf(1, "debug2");
        //             dprintf(1, "current = %d\n", a->value);
        // dprintf(1,  "next = %d\n", a->next->value);
        // dprintf(1, "prev = %d\n", a->prev->value);
            reverse_rotate_node(&a);
            printf("rra\n");
        } else if (list_is_sorted(a)) {
            if (a->value > b->value) {
                a = push_src_to_dst(&b, a);
                printf("pa\n");
            } else {
                rotate_node(&b);
                printf("rb\n");
            }
        } else {
            // dprintf(1, "debug3");

            b = push_src_to_dst(&a, b);
            printf("pb\n");
        }
        printf("Print List A\n");
        print_list(a);
        printf("Print List B\n");
        print_list(b);
                // dprintf(1, "current = %d\n", a->value);
        // dprintf(1,  "next = %d\n", a->next->value);
        // dprintf(1, "prev = %d\n", a->prev->value);
        // break;
        // dprintf(1, "debug4");

    }
    printf("-- list is sorted --");

}


void ft_putchar(char s){
    write(1, &s, 1);
}

// int main(void) {
//     ft_putchar(50);
// }