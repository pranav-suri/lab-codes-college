#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

void selection_sort(int arr[], int n)
{

    int i_min = 0, i, j;

    for (i = 0; i < n; i++)
    {
        i_min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i_min])
            {
                i_min = j;
            }
        }

        swap(&arr[i], &arr[i_min]);
    }
}

int main()
{
    int n = 6;
    int arr[] = {4, 6, 10, 3, 7, 1};

    printf("The array before sorting: \n");
    printArray(arr, n);

    selection_sort(arr, n);
    printf("The sorted array: \n");
    printArray(arr, n);

    return 0;
}
