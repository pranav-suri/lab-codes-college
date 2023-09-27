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

void bub_asc_itr(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = 1;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

void bub_dsc_itr(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swapped = 1;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

// recursive is unoptimized
void bub_asc_rec(int arr[], int len)
{
    if (len > 1)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
        bub_asc_rec(arr, len - 1);
    }
}

void bub_dsc_rec(int arr[], int len)
{
    if (len > 1)
    {
        for (int i = 0; i < len - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
            }
        }
        bub_dsc_rec(arr, len - 1);
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = 10;
    print_arr(arr, len);

    bub_asc_itr(arr, len);
    print_arr(arr, len);

    bub_dsc_itr(arr, len);
    print_arr(arr, len);

    bub_asc_rec(arr, len);
    print_arr(arr, len);

    bub_dsc_rec(arr, len);
    print_arr(arr, len);
    return 0;
}