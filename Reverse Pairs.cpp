#include <bits/stdc++.h> 

int merge(vector<int>& arr, int left, int mid, int right) {
    int count = 0;

    // Count the pairs where arr[i] > 2 * arr[j]
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right) {
        if ((long long)arr[i] > 2 * (long long)arr[j]) {
            count += (mid - i + 1);
            j++;
        } else {
            i++;
        }
    }

    // Merge the subarrays while sorting
    vector<int> temp(right - left + 1);
    int k = 0;
    i = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return count;
}

int mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    int count = mergeSort(arr, left, mid) + mergeSort(arr, mid + 1, right) + merge(arr, left, mid, right);
    return count;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	  int count = mergeSort(arr, 0, n - 1);
    return count;
}