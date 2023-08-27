#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sel_asc_iter(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int imin = i;
        for (int j = i; j < len; j++)
        {
            // Finding min index
            if (arr[j] < arr[imin])
            {
                imin = j;
            }
        }
        swap(&arr[i], &arr[imin]);
    }
}

void sel_dsc_iter(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int imax = i;
        for (int j = i; j < len; j++)
        {
            // Finding max element
            if (arr[j] > arr[imax])
            {
                imax = j;
            }
        }
        swap(&arr[i], &arr[imax]);
    }
}

void sel_dsc_rec(int arr[], int low, int high)
{
    if (high > low)
    {
        int imax = low;
        for (int j = low; j <= high; j++)
        {
            if (arr[j] > arr[imax])
            {
                imax = j;
            }
        }
        swap(&arr[low], &arr[imax]);
        sel_dsc_rec(arr, low + 1, high);
    }
}

void sel_asc_rec(int arr[], int low, int high)
{
    if (high > low)
    {
        int imin = low;
        for (int j = low; j <= high; j++)
        {
            if (arr[j] < arr[imin])
            {
                imin = j;
            }
        }
        swap(&arr[low], &arr[imin]);
        sel_asc_rec(arr, low + 1, high);
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = 10;
    print_arr(arr, len);

    sel_asc_iter(arr, len);
    print_arr(arr, len);

    sel_dsc_iter(arr, len);
    print_arr(arr, len);

    sel_asc_rec(arr, 0, len - 1);
    print_arr(arr, len);

    sel_dsc_rec(arr, 0, len - 1);
    print_arr(arr, len);
    return 0;
}