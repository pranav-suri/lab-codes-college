#include <iostream>
using namespace std;

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1; // Length of the left subarray
    int n2 = high - mid;    // Length of the right subarray

    // Temporary arrays to hold the two halves
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[low..high]
    int i = 0; // Initial index of the first subarray
    int j = 0; // Initial index of the second subarray
    int k = low; // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid); // Sort the first half
        mergeSort(arr, mid + 1, high); // Sort the second half

        merge(arr, low, mid, high); // Merge the sorted halves
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array: ";
    printArr(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    printArr(arr, arrSize);

    return 0;
}
