// Given a string and an integer k. In one operation any character of the string can be
// replaced with any english upper case character.
// Return the length of the longest substring that contain same character after performing
// at most k operation

// Input: s = "ABAB" k = 2      Input: s = "BSDDKKDJF" k = 3
// Output: 4                    Output: 6

#include <bits/stdc++.h>

using namespace std;

// Brute Force
// Time complexity: O(n^2)
// Space complexity O(1)

int longestSubstringBF(string s, int k)
{
    int n = s.size(), maxLength = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int hash[26] = {0}, maxFreq = INT_MIN;
        for (int j = i; j < n; j++)
        {
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            if (j - i + 1 - maxFreq <= k && j - i + 1 > maxLength)
                maxLength = j - i + 1;
        }
    }

    return maxLength;
}

// Optimal approach
// Time complexity: O(n)
// Space complexity O(1)

int longestSubstring(string s, int k)
{
    int n = s.size(), maxLength = INT_MIN, l = 0, r = 0, hash[26] = {0}, maxFreq = INT_MIN;
    while (r < n)
    {
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r] - 'A']);
        if (r - l + 1 - maxFreq > k)
        {
            hash[s[l] - 'A']--;
            l++;
        }
        maxLength = max(maxLength, r - l + 1);

        r++;
    }

    return maxLength;
}

int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << "Longest substring length with the same character can be: " << longestSubstring(s, k) << endl;
    cout << "Longest substring length with the same character can be: " << longestSubstringBF(s, k) << endl;
}