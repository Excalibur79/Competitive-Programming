// An efficient C++ program to find
// maximum of all minimums of
// windows of different sizes
#include <iostream>
#include <stack>
using namespace std;

void printMaxOfMin(int arr[], int n) {
    // Used to find previous and next smaller
    stack<int> s;

    // Arrays to store previous and next smaller
    int left[n + 1];
    int right[n + 1];

    // Initialize elements of left[] and right[]
    for (int i = 0; i < n; i++) {
        left[i] = -1;
        right[i] = n;
    }

    // Fill elements of left[] using logic discussed on
    // https://www.geeksforgeeks.org/next-greater-element/
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();

        if (!s.empty()) left[i] = s.top();

        s.push(i);
    }

    // Empty the stack as stack is
    // going to be used for right[]
    while (!s.empty()) s.pop();

    // Fill elements of right[] using same logic
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();

        if (!s.empty()) right[i] = s.top();

        s.push(i);
    }

    // Create and initialize answer array
    int ans[n + 1];
    for (int i = 0; i <= n; i++) ans[i] = 0;

    // Fill answer array by comparing minimums of all
    // lengths computed using left[] and right[]
    for (int i = 0; i < n; i++) {
        // length of the interval
        int len = right[i] - left[i] - 1;

        // arr[i] is a possible answer for this length
        // 'len' interval, check if arr[i] is more than
        // max for 'len'
        ans[len] = max(ans[len], arr[i]);
    }

    // Some entries in ans[] may not be filled yet. Fill
    // them by taking values from right side of ans[]
    for (int i = n - 1; i >= 1; i--) ans[i] = max(ans[i], ans[i + 1]);

    // Print the result
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

// Driver program
int main() {
    int arr[] = {10, 20, 30, 50, 40, 70, 31};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxOfMin(arr, n);
    return 0;
}
