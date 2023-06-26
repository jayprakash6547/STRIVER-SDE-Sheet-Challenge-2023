string kthPermutation(int n, int k) {
    vector<int> factorial(n, 1);
    vector<int> nums(n, 1);

    // Calculate factorials
    for (int i = 1; i < n; i++) {
        factorial[i] = factorial[i - 1] * i;
        nums[i] = i + 1;
    }

    // Adjust k to 0-based index
    k--;

    string result;
    for (int i = n - 1; i >= 0; i--) {
        int index = k / factorial[i];
        k %= factorial[i];

        result += to_string(nums[index]);
        nums.erase(nums.begin() + index);
    }

    return result;
}
