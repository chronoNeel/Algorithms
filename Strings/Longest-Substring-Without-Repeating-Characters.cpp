// Given a string s. Find the length of the longest substring without repeating characters.
// Input: s = "abcabcbb"    Input: s = "bbbbb"
// Output: 3                Output: 1

#include <bits/stdc++.h>

using namespace std;


// Brute force
// Time complexity: O(n^2)
// Space complexity: O(1)

int longestSubstringBF (string s) {
    int n = s.size(), maxLength = INT_MIN;
    for (int i = 0; i < n; i++) {
        int hash[256] = {0};
        for (int j = i; j < n; j++) {
            if (hash[s[j]]) break;
            maxLength = max (maxLength, j - i + 1);
            hash[s[j]]++;
        }
    }

    return maxLength;
}

// Optimal approach with sliding window
// Time complexity: O(n)
// Space complexity: O(1)

int longestSubstring (string s) {
    int n = s.size(), l = 0, r = 0, maxLength = INT_MIN, hash[265];
    memset (hash, -1, sizeof(hash));

    while (r < n) {
        if(hash[s[r]] != -1 && hash[s[r]] >= l) {
            l = hash[s[r]] + 1;
        }
        hash[s[r]] = r;
        maxLength = max (maxLength, r - l + 1);
        r++;
    }

    return maxLength;
}

int main () 
{
    string s;
    cin >> s;
    cout << "Length of the longest substring without repeating characters is: " << longestSubstring(s) << endl;
    cout << "Length of the longest substring without repeating characters is: " << longestSubstringBF(s);
}