int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	 if (n == 0) {
        return 0;
    }
    
    int j = 0; // Index to track the last unique element
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++; // Move to the next unique element
            arr[j] = arr[i]; // Overwrite the current element with the unique element
        }
    }
    
    return j + 1; // Return the length of the modified array
}