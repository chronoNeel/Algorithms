// Given a string s, return the number of palindromic substrings in it.
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

#include <bits/stdc++.h>

using namespace std;

// Brute force approach
// Time complexity: O(n^3)
// Space complexity: O(1)

int countSubstringsBF(string s)
{
    int count = 0, n = s.size();
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
            if (!flag)
                count++;
        }
    }

    return count;
}

// Expand Around Center Approach
// Time complexity: O(n^2)
// Space complexity: O(1)

void expand(string &s, int l, int r, int &count, int n)
{
    while (r < n && l >= 0 && s[l] == s[r])
    {
        count++;
        l--;
        r++;
    }
}

int countSubstrings(string s)
{
    int count = 0, n = s.size();
    for (int i = 0; i < n; i++)
    {
        expand(s, i, i, count, n);
        expand(s, i, i + 1, count, n);
    }

    return count;
}

int main()
{
    string s;
    cin >> s;

    cout << "Number of Palindromic Strings are: " << countSubstrings(s) << endl;
    cout << "Number of Palindromic Strings are: " << countSubstringsBF(s);

    return 0;
}