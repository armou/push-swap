#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int convert;
    int index;
    int *array_a;
    int *array_b;

    array_a = malloc(sizeof(int) * (argc - 1));
    array_b = malloc(sizeof(int) * (argc - 1));

    index = 0;

    printf("argc value = %d\n\n\n", argc);
    while (index + 1 < argc) {
        convert = atoi(argv[index + 1]);
        array_a[index] = convert;
        printf("%d\n", array_a[index]);
  //      printf("%d", sizeof(array));
        index++;
    }

    int sorted;
    index = 0;
    sorted = 0;
    while (!sorted) {
        if (array_a[index] > array_a[index + 1] && index + 1 < argc - 1) {
            int swap;
            swap = array_a[index];
            array_a[index] = array_a[index+1];
            array_a[index+1] = swap;
            printf("swap index value = %d\n", index);
            index = 0;
        } else {
            index++;
            printf("index value = %d\n", index);
            if (index == argc - 1) {
                sorted = 1;
            }
        }
    }
    index = 0;
    printf("----------------------------\n\n");
    while (index < argc - 1) {
        printf("last loop");
        printf("%d\n", array_a[index]);
        index++;
    }
//    write(1, "\n", 1);
    return 0;
}