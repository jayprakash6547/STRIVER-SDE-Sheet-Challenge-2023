#include <bits/stdc++.h> 



void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& subsets) {
    // Add the current subset to the result
    subsets.push_back(current);

    // Generate subsets by considering each element from the current index onwards
    for (int i = index; i < nums.size(); i++) {
        // Skip duplicate elements to ensure uniqueness
        if (i > index && nums[i] == nums[i - 1])
            continue;

        // Add the current element to the current subset
        current.push_back(nums[i]);

        // Generate subsets recursively by moving to the next index
        generateSubsets(i + 1, nums, current, subsets);

        // Backtrack by removing the current element from the current subset
        current.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>>subsets;
    vector<int>current;
    sort(arr.begin(),arr.end());
    generateSubsets(0,arr,current,subsets);
    return subsets;
}