#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{ // Find the first decreasing element from the right
    int i = n - 2;
    while (i >= 0 && permutation[i] >= permutation[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Find the element just larger than the one at index i
        int j = n - 1;
        while (j > i && permutation[j] <= permutation[i]) {
            j--;
        }

        // Swap the elements at indices i and j
        swap(permutation[i], permutation[j]);
    }

    // Reverse the subarray from index i + 1 to the end
    reverse(permutation.begin() + i + 1, permutation.end());

    return permutation;
}

// Function to print the vector
void printVector(const vector<int>& permutation) {
    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;
}