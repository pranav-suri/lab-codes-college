#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void merge(int a[], int mid, int low, int high)
{

    int i, j, k, b[20];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }

        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void merge_sort(int a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);

        merge(a, mid, low, high);
    }
}

int main()
{

    int n = 9;
    int arr[] = {5, 2, 1, 3, 4, 6, 9, 8, 7};
    int low = 0, high = 8;

    printf("The array before sorting: \n");
    printArray(arr, n);

    merge_sort(arr, low, high);

    printf("The sorted array: \n");
    printArray(arr, n);

    return 0;
}
