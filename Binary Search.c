#include <stdio.h>

int bin_search_recursive(int arr[], int key, int ilow, int ihigh)
{
    if (ihigh >= ilow)
    {
        int imid = (ihigh + ilow) / 2;
        if (key > arr[imid])
        {
            int ilow = imid + 1;
            return bin_search_recursive(arr, key, ilow, ihigh);
        }
        else if (key < arr[imid])
        {
            int ihigh = imid - 1;
            return bin_search_recursive(arr, key, ilow, ihigh);
        }
        if (key == arr[imid])
        {
            return imid;
        }
    }
    return -1;
}

int bin_search_iterative(int arr[], int key, int ilow, int ihigh)
{
    int imid;
    do
    {
        imid = (ilow + ihigh) / 2;

        if (key > arr[imid])
        {
            ilow = imid + 1;
        }
        else if (key < arr[imid])
        {
            ihigh = imid - 1;
        }

        if (key == arr[imid])
        {
            return imid;
        }
    } while (ihigh >= ilow);
    return -1;
}

int main()
{
    int arr[] = {2, 4, 8, 16, 23, 56, 78, 89};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 23; // Element to be searched
    int ihigh = len, ilow = 0;

    int iIter = bin_search_iterative(arr, key, ilow, ihigh);
    int iRecur = bin_search_recursive(arr, key, ilow, ihigh);

    if (iIter != -1)
    {
        printf("Using Recursion: Element at index: %d\n", iRecur);
    }

    if (iRecur != -1)
    {
        printf("Using Iteration: Element at index: %d\n", iIter);
    }

    else
    {
        printf("Element not found.");
    }
    return 0;
}
