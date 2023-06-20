int calculateMinPatforms(int at[], int dt[], int n) {

    // Sort the arrival and departure times in ascending order
    sort(at, at + n);
    sort(dt, dt + n);

    int platforms = 1; // At least one platform is required
    int minPlatforms = 1; // Minimum platforms needed at any point
    int i = 1; // Pointer for arrival times
    int j = 0; // Pointer for departure times

    // Traverse the arrival and departure times
    while (i < n && j < n) {
        if (at[i] <= dt[j]) {
            // Train is arriving, increment the platforms count
            platforms++;
            i++;
        } else {
            // Train is departing, decrement the platforms count
            platforms--;
            j++;
        }

        // Update the minimum platforms needed
        minPlatforms = max(minPlatforms, platforms);
    }

    return minPlatforms;
}
