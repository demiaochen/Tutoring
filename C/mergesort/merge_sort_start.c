# include<stdio.h>
# include<stdlib.h>


void print_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int * merge_sort (int *arr, int len) {
    return arr;
}


int main() {
    // a primitive array: a pointer to the first item in the array
    int arr[] = {3, 2, 5, 1, 8, 5, 9};
    int len = sizeof(arr) / sizeof(*arr);

    printf("Before sorting: ");
    print_array(arr, len);

    int *sorted_arr = merge_sort(arr, len);

    printf("After sorting:  ");
    print_array(sorted_arr, len);

    return 0;
}
