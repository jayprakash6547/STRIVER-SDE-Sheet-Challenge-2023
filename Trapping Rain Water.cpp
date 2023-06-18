#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n) {
    long res = 0;

    long lMax[n];
    long rMax[n];

    lMax[0] = arr[0];
    for (int i = 1; i < n; i++)
        lMax[i] = max(arr[i], lMax[i - 1]);

    rMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rMax[i] = max(arr[i], rMax[i + 1]);

    for (int i = 1; i < n - 1; i++)
        res = res + (min(lMax[i], rMax[i]) - arr[i]);

    return res;
}
