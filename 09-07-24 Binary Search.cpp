#include <iostream>
using namespace std;

void arrInput(int *&arr, int length) {
    arr = new int[length];
    cout << "Enter number of elements in sorted array: " << endl;
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
}

int binarySearchRecursive(int arr[], int key, int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[mid] < key) {
        return binarySearchRecursive(arr, key, mid + 1, high);
    }
    return binarySearchRecursive(arr, key, low, mid - 1);
}

int binarySearch(int arr[], int key, int length) {
    int low = 0;
    int high = length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int *arr;

    int length;
    cout << "Enter number of elements: ";
    cin >> length;

    arrInput(arr, length);

    int key;
    cout << "Enter number to search: ";
    cin >> key;

    int iterativeResult = binarySearch(arr, key, length);
    int recursiveResult = binarySearchRecursive(arr, key, 0, length - 1);
    if ((iterativeResult >= 0) && (recursiveResult >= 0)) {
        cout << "Iterative binary search - Key found: " << key
             << " at index: " << iterativeResult << endl;
        cout << "Recursive binary search - Key found: " << key
             << " at index: " << recursiveResult << endl;
    } else {
        cout << "Key not found.";
    }
    return 0;
}
