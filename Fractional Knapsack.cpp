#include <bits/stdc++.h> 


bool compare(pair<int, int> a, pair<int, int> b) {
    double valuePerWeightA = (double)a.second / a.first;
    double valuePerWeightB = (double)b.second / b.first;
    return valuePerWeightA > valuePerWeightB;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].first <= w) {
            currentWeight += items[i].first;
            totalValue += items[i].second;
        } else {
            int remainingWeight = w - currentWeight;
            totalValue += (double)remainingWeight / items[i].first * items[i].second;
            break;
        }
    }

    return totalValue;
}