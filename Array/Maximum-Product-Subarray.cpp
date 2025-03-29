// Given an integer array, find a subarray that has the largest product, and return the product.

#include<bits/stdc++.h>

using namespace std;

int maxSubArrayProd (vector<int> arr) {
    int n = arr.size(), suff = 1, pref = 1, res = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (suff == 0) suff = 1;
        if (pref == 0) pref = 1;

        suff = suff * arr[i];
        pref = pref * arr[n-1-i];

        res = max ({res, suff, pref});
    }

    return res;
}

int kadane (vector<int> arr) {
    int n = arr.size(), maxProd, minProd, res = INT_MIN;
    maxProd = minProd = arr[0];

    for (int i = 1; i < n; i++) {
        int temp = maxProd;
        maxProd = max ({arr[i], maxProd * arr[i], minProd * arr[i]});
        minProd = min ({arr[i], minProd * arr[i], temp * arr[i]});

        res = max ({res, maxProd, minProd});
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum subarray sum is " << kadane (arr);
}


/*
9
-2 1 -3 4 -1 2 1 -5 4

5
5 4 -1 7 8
*/