#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
		unordered_set<int>set;
    for (int num : arr) {
        // If the element is already present in the set, it's a duplicate
        if (set.count(num) > 0) {
            return num;
        } else {
            set.insert(num);
        }
    }
    
    // If no duplicates found
    return -1;
}
