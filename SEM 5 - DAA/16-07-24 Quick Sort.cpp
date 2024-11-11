#include <iostream>
using namespace std;

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(int arr[], int low, int high, int len) {
    if (low < high) {
        int pivot = arr[high];
        int higher = low;
        int lower = high;

        while (true) {
            while (true) {
                if (arr[higher] >= pivot || higher == high) {
                    break;
                }
                higher++;
            }
            while (true) {
                if (arr[lower] < pivot || lower == low) {
                    break;
                }
                lower--;
            }
            if (higher >= lower) {
                break;
            }
            swap(arr[higher], arr[lower]);
        }
        swap(arr[high], arr[higher]);

        printArr(arr, len);
        quickSort(arr, low, higher - 1, len);
        quickSort(arr, higher + 1, high, len);
    }
}

int main() {
    int arr[] = {4, 7, 8, 9, 1, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, len);
    quickSort(arr, 0, len - 1, len);
    // cout << "Sorted Array\n";
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    return 0;
}