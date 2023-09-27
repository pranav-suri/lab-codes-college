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

void qck_asc_high_rec(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low, j = high - 1;
    if (low < high)
    {
        while (i < j)
        {
            for (i = i; i <= high; i++)
            {
                if (arr[i] >= pivot)
                {
                    break;
                }
            }
            for (j = j; j >= low; j--)
            {
                if (arr[j] <= pivot)
                {
                    break;
                }
            }
            if (i < j)
            {
                swap(&arr[i], &arr[j]);
            }
            else
            {
                swap(&arr[high], &arr[i]);
            }
        }
        qck_asc_high_rec(arr, low, i - 1);
        qck_asc_high_rec(arr, i + 1, high);
    }
}

void qck_asc_low_rec(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high;
    if (low < high)
    {
        while (i < j)
        {
            for (i = i; i <= high; i++)
            {
                if (arr[i] >= pivot)
                {
                    break;
                }
            }
            for (j = j; j >= low; j--)
            {
                if (arr[j] <= pivot)
                {
                    break;
                }
            }
            if (i < j)
            {
                swap(&arr[i], &arr[j]);
            }
            else
            {
                swap(&arr[low], &arr[j]);
            }
        }
        qck_asc_low_rec(arr, low, j - 1);
        qck_asc_low_rec(arr, j + 1, high);
    }
}

void qck_dsc_high_rec(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low, j = high - 1;
    if (low < high)
    {
        while (i < j)
        {
            for (i = i; i <= high; i++)
            {
                if (arr[i] <= pivot)
                {
                    break;
                }
            }
            for (j = j; j >= low; j--)
            {
                if (arr[j] >= pivot)
                {
                    break;
                }
            }
            if (i < j)
            {
                swap(&arr[i], &arr[j]);
            }
            else
            {
                swap(&arr[high], &arr[i]);
            }
        }
        qck_dsc_high_rec(arr, low, i - 1);
        qck_dsc_high_rec(arr, i + 1, high);
    }
}

void qck_dsc_low_rec(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high;
    if (low < high)
    {
        while (i < j)
        {
            for (i = i; i <= high; i++)
            {
                if (arr[i] <= pivot)
                {
                    break;
                }
            }
            for (j = j; j >= low; j--)
            {
                if (arr[j] >= pivot)
                {
                    break;
                }
            }
            if (i < j)
            {
                swap(&arr[i], &arr[j]);
            }
            else
            {
                swap(&arr[low], &arr[j]);
            }
        }
        qck_dsc_low_rec(arr, low, j - 1);
        qck_dsc_low_rec(arr, j + 1, high);
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = 10;
    print_arr(arr, len);

    qck_asc_high_rec(arr, 0, 9);
    print_arr(arr, len);

    qck_dsc_low_rec(arr, 0, 9);
    print_arr(arr, len);

    qck_asc_low_rec(arr, 0, 9);
    print_arr(arr, len);

    qck_dsc_high_rec(arr, 0, 9);
    print_arr(arr, len);

    return 0;
}