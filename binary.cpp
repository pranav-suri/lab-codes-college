#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int binarySearch(vector<int> arr, int left, int right, int target) {
    if (left <= right) {
        int mid = (right + left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (target < arr[mid]) {
            return binarySearch(arr, left, mid - 1, target);
        }

        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}

int main() {
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements (sorted for binary search): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> target;

    int linearResult = linearSearch(arr, n, target);
    cout << "Linear index: " << linearResult << endl;

    int binaryResult = binarySearch(arr, 0, n - 1, target);
    cout << "Binary index: " << binaryResult << endl;

    return 0;
}
