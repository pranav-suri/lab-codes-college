#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = 0;
    temp = *y;
    *y = *x;
    *x = temp;
}

int main()
{
    int flag, rounds = 0;

    int arr[] = {7, 3, 9, 4, 5};
    int n = 5;

    for (int i = 0; i < n - 1; i++)
    {
        rounds++;
        flag = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                swap(&arr[j], &arr[j + 1]);
            }
        }

        if (flag == 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The number of rounds it took to sort: %d", rounds);
}
