// Given an integer array, find a subarray that has the largest sum, and return the sum.


#include<bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int res, sum;
    res = sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        sum = max (sum + nums[i], nums[i]);
        res = max (res, sum);
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

    cout << "Maximum subarray sum is " << maxSubArray (arr);
}

/*
9
-2 1 -3 4 -1 2 1 -5 4

5
5 4 -1 7 8
*/