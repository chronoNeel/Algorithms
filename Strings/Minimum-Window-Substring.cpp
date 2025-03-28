// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that 
// every character in t (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".



#include <bits/stdc++.h>

using namespace std;

string minWindow (string s, string t) {
    int start = -1, minLength = INT_MAX, cnt = 0, n = s.size(), m = t.size(), l = 0, r = 0;
    unordered_map<char, int> hash;

    for (auto ch : t) hash[ch]++;

    while (r < n) {
        if (hash[s[r]] > 0) cnt++;
        hash[s[r]]--; // Taking the character inside window
        
        while (cnt == m) { // Window contains all the characters from t
            if (r-l+1 < minLength) {
                minLength = r-l+1;
                start = l;
            }

            hash[s[l]]++; // Removing the character from the left
            if (hash[s[l]] > 0) cnt --;
            l++; // Shrinking the window
        }

        r++;
    }

    return (start == -1) ? "" : s.substr(start, minLength);
}


int main ()
{
    string s, t;
    cin >> s >> t;

    cout << "Segment of " << s << " that contains all the characters of " << t << " is: " << minWindow (s, t);

    return 0;
}


/*
ADOBECODEBANC
ABC
*/