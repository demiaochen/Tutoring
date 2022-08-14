# include<stdio.h>
# include<stdlib.h>


void print_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// combine two sorted subarrays into one sorted array
int * merge(int *left, int *right, int len_left, int len_right) {
    int *result = malloc(sizeof(int) * (len_left + len_right));
    int i = 0, j = 0, k = 0;
    while (i < len_left && j < len_right) {
        if (left[i] < right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }
    while (i < len_left) {
        result[k++] = left[i++];
    }
    while (j < len_right) {
        result[k++] = right[j++];
    }
    return result;
}


// return a sorted array
int * merge_sort (int *arr, int len) {
    if (len <= 1) {
        return arr;
    }

    // divide the array into two subarrays
    int mid = (len + 1) / 2;  // in C: int 7/2 = 3
    int *left = malloc(sizeof(int) * mid);
    int *right = malloc(sizeof(int) * len / 2);
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < len; i++) {
        right[i - mid] = arr[i];
    }

    left = merge_sort(left, mid);
    right = merge_sort(right, len / 2);

    int *result = merge(left, right, mid, len / 2);

    free(left);
    free(right);

    return result;
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
