// Given a string s, return the longest palindromic substring in s.
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

#include <bits/stdc++.h>

using namespace std;

// Expand Around Center Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

void expand (string s, int l, int r, int& left, int& maxLength) {
    int n = s.size();

    while (l >= 0 && r < n && s[l] == s[r]) {
        if (r - l + 1 > maxLength) {
            maxLength = r - l + 1;
            left = l;
        }
        l--;
        r++;
    }

}

string longestPalindrome (string s) {
    int n = s.size(), maxLength = INT_MIN, left;
    for (int i = 0; i < n; i++) {
        expand (s, i, i, left, maxLength);
        expand (s, i, i+1, left, maxLength);
    }

    return s.substr(left, maxLength);
}

// Brute force approach
// Time complexity: O(n^3)
// Space complexity: O(1)

string longestPalindromeBF(string s)
{
    int maxLength = INT_MIN, start, n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int left = i, right = j, flag = 0;
            while (left <= right)
            {
                if (s[left] != s[right])
                    flag = 1;
                left++;
                right--;
            }
            if (!flag && j-i+1 > maxLength) {
                maxLength = j-i+1;
                start = i;
            }
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string s;
    cin >> s;

    cout << "Longest Palindrome is " << longestPalindrome (s) << endl;
    cout << "Longest Palindrome is " << longestPalindromeBF (s) << endl;
}