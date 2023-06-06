#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
     long long currentSum = arr[0];
    long long maxSum = arr[0];

    for (int i = 1; i < n; i++) {
        // Calculate the maximum sum ending at the current position
        currentSum = max(static_cast<long long>(arr[i]), currentSum + arr[i]);

        // Update the maximum sum seen so far
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;

}