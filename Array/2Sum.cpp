#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum (vector<int>& arr, int target) {
    unordered_map <int, int> hash;
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (hash.find(complement) != hash.end()) {
            return {i, hash[complement]};
        }

        hash[arr[i]] = i;
    }

    return {};
}

int main()
{
    int n, target;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> target;
    auto res = twoSum (arr, target);

    cout << res[0] << " " << res[1];
}

/*
4
2 7 11 15
9

9
-2 1 -3 4 -1 2 1 -5 4
6
*/
