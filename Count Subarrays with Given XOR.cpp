#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
      unordered_map<int, int> xor_map;
    int count = 0;
    int current_xor = 0;

    for (int i = 0; i < arr.size(); ++i) {
        current_xor ^= arr[i];

        if (current_xor == x)
            count++;

        if (xor_map.find(current_xor ^ x) != xor_map.end())
            count += xor_map[current_xor ^ x];

        xor_map[current_xor]++;
    }

    return count;
}