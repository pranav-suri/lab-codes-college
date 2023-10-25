#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void insertion_sort(int *arr, int n)
{

    int i, j, key = 0;

    for (i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{

    int arr[] = {5, 2, 1, 3, 4, 6};
    int n = 6;

    printf("The array before sorting: \n");
    printArray(arr, n);

    insertion_sort(arr, n);
    printf("The sorted array: \n");
    printArray(arr, n);

    return 0;
}
