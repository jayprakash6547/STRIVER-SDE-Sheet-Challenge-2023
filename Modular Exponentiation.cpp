#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	  if (n == 0)
        return 1;

    long long result = 1;
    long long base = x % m;

    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        n /= 2;
    }

    return result;
}