#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
    // Write your code here.
    int candidate = 0;
    int count = 0;

    // Find a potential candidate for the majority element
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (candidate == arr[i]) {
            count++;
        } else {
            count--;
        }
    }

    // Verify if the candidate is the majority element
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate;
    } else {
        return -1;  // No majority element found
    }
}