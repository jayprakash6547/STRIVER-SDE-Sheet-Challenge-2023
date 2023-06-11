#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  unordered_map<int, int> sum_map;
    int max_length = 0;
    int current_sum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        current_sum += arr[i];

        if (arr[i] == 0 && max_length == 0)
            max_length = 1;

        if (current_sum == 0)
            max_length = i + 1;

        if (sum_map.find(current_sum) != sum_map.end())
            max_length = max(max_length, i - sum_map[current_sum]);
        else
            sum_map[current_sum] = i;
    }

    return max_length;

}