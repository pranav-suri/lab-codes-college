#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> MinHeap;

void printMinHeap(MinHeap minHeap) {
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int optimalMergePattern(const vector<int>& files) {
    MinHeap minHeap(files.begin(), files.end());
    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        int mergeCost = first + second;
        totalCost += mergeCost;

        minHeap.push(mergeCost);
        printMinHeap(minHeap);
    }

    return totalCost;
}

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    vector<int> now(n);
    cout << "Enter the sizes of the now: ";
    for (int i = 0; i < n; ++i) {
        cin >> now[i];
    }

    int result = optimalMergePattern(now);
    cout << "The minimum cost to merge all now is: " << result << endl;

    return 0;
}
