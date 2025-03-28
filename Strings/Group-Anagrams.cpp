// Given an array of strings strs, group the anagrams together.
// Return the group of anagrams at any order
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

#include <bits/stdc++.h>

using namespace std;

// Time complexity: O(nklogk), iterate n strings and sort strings length k
// Space complexity: O(nk)

vector<vector<string>> groupAnagram_usingSorting(vector<string> strs)
{
    unordered_map<string, vector<string>> hash;
    for (auto str : strs)
    {
        string temp = str;
        sort(str.begin(), str.end());
        hash[str].push_back(temp);
    }

    vector<vector<string>> res;
    for (auto pair : hash)
    {
        res.push_back(pair.second);
    }

    return res;
}

// Time complexity: O(nk)
// Space complexity: O(nk)

vector<vector<string>> groupAnagram_usingFrequency(vector<string> strs) {
    unordered_map<string, vector<string>> hash;
    for (auto str : strs) {
        int count[26] = {0}; 
        for (auto ch : str) {
            count[ch - 'a']++;
        }
        string key;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                key += string(1, 'a' + i) + to_string(count[i]); 
            }
        }
        hash[key].push_back(str);
    }
    vector<vector<string>> res;
    for (auto pair : hash) {
        res.push_back(pair.second);
    }
    return res;
}

void print(vector<vector<string>> groups)
{
    for (auto group : groups)
    {
        cout << "[ ";
        for (auto str : group)
            cout << str << " ";
        cout << " ]\n";
    }
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groups = groupAnagram_usingSorting(strs);
    cout << "Group anagram using sorting" << endl;
    print(groups);

    groups = groupAnagram_usingFrequency(strs);
    cout << "Group anagram using frequency" << endl;
    print(groups);
}
