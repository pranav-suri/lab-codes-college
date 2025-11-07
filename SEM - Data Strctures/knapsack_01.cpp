#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, const vector<int>& weight, const vector<int>& value, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i - 1] <= w) { // if item weight < current capacity
                dp[i][w] = max(dp[i - 1][w], value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    vector<int> weight(n), value(n);
    cout << "Enter the weights and values of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    int maxValue = knapsack(W, weight, value, n);
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
