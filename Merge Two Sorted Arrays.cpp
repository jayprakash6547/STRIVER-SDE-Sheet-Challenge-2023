#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    vector<int> merged(m + n);  // Resultant merged array
    int i = m - 1;  // Index for elements in arr1
    int j = n - 1;  // Index for elements in arr2
    int k = m + n - 1;  // Index for elements in merged array

    // Merge the arrays from the end
    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            merged[k--] = arr1[i--];
        } else {
            merged[k--] = arr2[j--];
        }
    }

    // Copy the remaining elements from arr1, if any
    while (i >= 0) {
        merged[k--] = arr1[i--];
    }

    // Copy the remaining elements from arr2, if any
    while (j >= 0) {
        merged[k--] = arr2[j--];
    }

    return merged;
}
