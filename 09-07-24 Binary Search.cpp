#include <iostream>
using namespace std;

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
    int arr[] = {3, 5, 11, 12, 17};
    int length = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter number to search: ";
    cin >> key;

    int iterativeResult = binarySearch(arr, key, length);
    int recursiveResult = binarySearchRecursive(arr, key, 0, length - 1);

    cout << "Iterative binary search - Key found: " << key << " at position: " << iterativeResult << endl;
    cout << "Recursive binary search - Key found: " << key << " at position: " << recursiveResult << endl;

    return 0;
}
