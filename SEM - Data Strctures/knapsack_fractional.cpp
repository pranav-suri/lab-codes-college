#include <bits/stdc++.h>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(const Item& a, const Item& b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (const Item& item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        }
        else {
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
    }

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
