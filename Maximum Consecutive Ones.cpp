int longestSubSeg(vector<int>& arr, int n, int k) {
    int maxOnes = 0; // Maximum consecutive ones
    int zeroCount = 0; // Count of zeros in the current window
    int start = 0; // Start of the current window
    
    for (int end = 0; end < n; end++) {
        if (arr[end] == 0) {
            zeroCount++; // Increment zero count
            
            // If the number of zeros exceeds k, move the start of the window
            while (zeroCount > k) {
                if (arr[start] == 0) {
                    zeroCount--; // Decrement zero count
                }
                start++; // Move the start of the window
            }
        }
        
        // Update the maximum number of ones if the current window is longer
        maxOnes = max(maxOnes, end - start + 1);
    }
    
    return maxOnes;
}
