#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	stack<int> stack;

    for (int i = 0; i < n; i++) {
        stack.push(i);
    }

    while (stack.size() > 1) {
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();

        if (knows(a, b)) {
            stack.push(b);
        } else {
            stack.push(a);
        }
    }

    int ans = stack.top();
    stack.pop();

    for (int i = 0; i < n; i++) {
        if (i != ans) {
            if (knows(ans, i) || !knows(i, ans)) {
                return -1;
            }
        }
    }

    return ans;
}