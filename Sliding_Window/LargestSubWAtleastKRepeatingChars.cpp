// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of
// the longest substring
int longestSubstring(string s, int k)
{
	// Store the required answer
	int ans = 0;

	// Create a frequency map of the
	// characters of the string
	int freq[26] = { 0 };

	// Store the length of the string
	int n = s.size();

	// Traverse the string, s
	for (int i = 0; i < n; i++)

		// Increment the frequency of
		// the current character by 1
		freq[s[i] - 'a']++;

	// Stores count of unique characters
	int unique = 0;

	// Find the number of unique
	// characters in string
	for (int i = 0; i < 26; i++)
		if (freq[i] != 0)
			unique++;

	// Iterate in range [1, unique]
	for (int curr_unique = 1;curr_unique <= unique;curr_unique++) {
		// Initialize frequency of all
		// characters as 0
		memset(freq, 0, sizeof(freq));

		// Stores the start and the
		// end of the window
		int start = 0, end = 0;

		// Stores the current number of
		// unique characters and characters
		// occuring atleast K times
		int cnt = 0, count_k = 0;

		while (end < n) {
			if (cnt <= curr_unique) {
				int ind = s[end] - 'a';

				// New unique character
				if (freq[ind] == 0)
					cnt++;

				freq[ind]++;

				// New character which
				// occurs atleast k times
				if (freq[ind] == k)
					count_k++;

				// Expand window by
				// incrementing end by 1
				end++;
			}
			else {
				int ind = s[start] - 'a';

				// Check if this character
				// is present atleast k times
				if (freq[ind] == k)
					count_k--;

				freq[ind]--;

				// Check if this character
				// is unique
				if (freq[ind] == 0)
					cnt--;

				// Shrink the window by
				// incrementing start by 1
				start++;
			}

			// If there are curr_unique
			// characters and each character
			// is atleast k times
			if (cnt == curr_unique
				&& count_k == curr_unique)

				// Update the overall
				// maximum length
				ans = max(ans, end - start);
		}
	}

	// Print the answer
	cout << ans;
}

// Driver Code
int main()
{
	string S = "ababbc";
	int K = 2;
	longestSubstring(S, K);

	return 0;
}
