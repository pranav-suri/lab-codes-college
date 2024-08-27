#include <iostream>
using namespace std;

void arrInput(int *&arr, int length) {
    arr = new int[length];
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
}

int linearSearch(int arr[], int key, int length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int linearSearchRecursive(int arr[], int key, int index, int length) {
    if (index >= length) {
        return -1;
    }
    if (arr[index] == key) {
        return index;
    }
    return linearSearchRecursive(arr, key, index + 1, length);
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

    int iterativeResult = linearSearch(arr, key, length);
    int recursiveResult = linearSearchRecursive(arr, key, 0, length);
    if ((iterativeResult >= 0) && (recursiveResult >= 0)) {
        cout << "Iterative linear search - Key found: " << key
             << " at index: " << iterativeResult << endl;
        cout << "Recursive linear search - Key found: " << key
             << " at index: " << recursiveResult << endl;
    } else {
        cout << "Key not found.";
    }
    return 0;
}
