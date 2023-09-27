#include <stdio.h>

linear_search(int arr[], int len, int key)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int arr[] = {2, 4, 8, 16, 23, 56, 78, 89};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 23; // Element to be searched

    int i = linear_search(arr, len, key);

    if (i != -1)
    {
        printf("Element at index: %d\n", i);
    }
    return 0;
}