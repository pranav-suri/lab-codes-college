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

void ins_asc_itr(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            for (int j = i + 1; j > 0; j--)
            {
                if (arr[j] < arr[j - 1])
                {
                    swap(&arr[j], &arr[j - 1]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void ins_dsc_itr(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            for (int j = i + 1; j > 0; j--)
            {
                if (arr[j] > arr[j - 1])
                {
                    swap(&arr[j], &arr[j - 1]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void ins_asc_rec(int arr[], int low, int high)
{
    if (low < high)
    {
        if (arr[low] > arr[low + 1])
        {
            for (int j = low + 1; j > low; j--)
            {
                if (arr[j] < arr[j - 1])
                {
                    swap(&arr[j], &arr[j - 1]);
                }
                else
                {
                    break;
                }
            }
        }
        ins_asc_rec(arr, low + 1, high);
    }
}

void ins_dsc_rec(int arr[], int low, int high)
{
    if (low < high)
    {
        if (arr[low] < arr[low + 1])
        {
            for (int j = low + 1; j > low; j--)
            {
                if (arr[j] > arr[j - 1])
                {
                    swap(&arr[j], &arr[j - 1]);
                }
                else
                {
                    break;
                }
            }
        }
        ins_asc_rec(arr, low + 1, high);
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = 10;
    print_arr(arr, len);

    ins_asc_itr(arr, len);
    print_arr(arr, len);

    ins_dsc_itr(arr, len);
    print_arr(arr, len);
    return 0;
}