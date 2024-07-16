#include <iostream>
using namespace std;

int linearSearch(int arr[], int key, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int linearSearchRecursive(int arr[], int key, int index, int length)
{
    if (index >= length)
    {
        return -1;
    }
    if (arr[index] == key)
    {
        return index;
    }
    return linearSearchRecursive(arr, key, index + 1, length);
}

int main()
{
    int arr[] = {3, 5, 11, 12, 17};
    int length = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter number to search: ";
    cin >> key;

    int iterativeResult = linearSearch(arr, key, length);
    int recursiveResult = linearSearchRecursive(arr, key, 0, length);

    cout << "Iterative search - Key found: " << key << " at position: " << iterativeResult << endl;
    cout << "Recursive search - Key found: " << key << " at position: " << recursiveResult << endl;

    return 0;
}
