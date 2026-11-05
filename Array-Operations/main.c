#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static void display_array(const int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(" ");
    }
    printf("\n");
}

int main(void) {
    int size, value, position;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size. Enter a positive integer.\n");
        return 1;
    }

    int *arr = malloc((size_t)size * sizeof *arr);
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d array elements:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid element.\n");
            free(arr);
            return 1;
        }
    }

    printf("\nOriginal ");
    display_array(arr, size);

    /* Insert a value at a zero-based position. */
    printf("\nEnter the value to insert: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid value.\n");
        free(arr);
        return 1;
    }

    printf("Enter insertion position (0 to %d): ", size);
    if (scanf("%d", &position) != 1 || position < 0 || position > size) {
        printf("Invalid insertion position.\n");
        free(arr);
        return 1;
    }

    int *larger = realloc(arr, (size_t)(size + 1) * sizeof *arr);
    if (larger == NULL) {
        printf("Memory reallocation failed.\n");
        free(arr);
        return 1;
    }
    arr = larger;

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    size++;

    printf("After insertion ");
    display_array(arr, size);

    /* Delete the first occurrence of the requested value. */
    printf("\nEnter the value to delete: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid value.\n");
        free(arr);
        return 1;
    }

    int found_index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Value %d was not found; array unchanged.\n", value);
    } else {
        for (int i = found_index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        printf("Deleted the first occurrence of %d.\n", value);
    }

    printf("Final ");
    display_array(arr, size);

    free(arr);
    return 0;
}
