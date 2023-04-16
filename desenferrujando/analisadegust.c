#include <stdio.h>
#include <string.h>

typedef struct {
    int index;
    int position;
    char character;
} Item;

char input[(int)1e5 + 666];

int less(Item a, Item b);
void merge(Item *arr, int left, int mid, int right);
void mergeSort(Item *arr, int left, int right);

int less(Item a, Item b) {
    return a.index == b.index ? a.position < b.position : a.index >= b.index;
}

void merge(Item *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Item L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (less(L[i], R[j]))
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(Item *arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    scanf("%s", input);
    int n = strlen(input);

    char cur_char = input[0];
    int start_position = 0;
    Item arr[(int)1e5 + 666];
    int arr_size = 0;

    for (int i = 0; i < n; ++i) {
        if (cur_char != input[i]) {
            arr[arr_size].index = i - start_position;
            arr[arr_size].character = cur_char;
            arr[arr_size].position = start_position;
            arr_size++;
            start_position = i;
            cur_char = input[start_position];
        }

        if (i == n - 1) {
            arr[arr_size].index = i - start_position + 1;
            arr[arr_size].character = cur_char;
            arr[arr_size].position = start_position;
            arr_size++;
        }
    }

    mergeSort(arr, 0, arr_size - 1);

    for (int i = 0; i < arr_size; ++i)
        printf("%d %c %d\n", arr[i].index, arr[i].character, arr[i].position);

    return 0;
}
