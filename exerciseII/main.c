#include <stdio.h>
#include <stdlib.h>

void print_ints(int *input_ints, int input_size) {
    for (int i = 0; i < input_size; i++) {
        printf("%d ", input_ints[i]);
    }
    printf("\n");
}

int main() {
    int *input_ints;
    int input_index = 0;
    int capacity = 5;
    int repeat = 1;

    input_ints = calloc(capacity, sizeof(int));

    if (input_ints == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter integers, when you want to stop enter 0: \n");
    while (repeat) {
        int number;
        scanf("%d", &number);

        if (number == 0) {
            repeat = 0;
        } else {
            if (input_index >= capacity) {
                capacity *= 2;
                input_ints = realloc(input_ints, capacity * sizeof(int));
                if (input_ints == NULL) {
                    printf("Memory reallocation failed\n");
                    return 1;
                }
            }
            input_ints[input_index] = number;
            input_index++;
        }
    }

    print_ints(input_ints, input_index);
    free(input_ints);
    return 0;
}
