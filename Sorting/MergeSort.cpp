#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void merge (vector<int>& arr, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        vector <int> larr (n1), rarr (n2);
        
        for (int i = 0; i < n1; i++) {
            larr [i] = arr [l + i];
        }
        for (int i = 0; i < n2; i ++) {
            rarr [i] = arr [mid + 1 + i];
        }
        
        int i = 0, j = 0, k = l;
        
        while (i < n1 && j < n2) {
            if (larr [i] <= rarr [j]) arr [k ++] = larr [i++];
            else arr [k ++] = rarr [j++];
        }
        
        while (i < n1) arr [k ++] = larr [i ++];
        while (j < n2) arr [k ++] = rarr [j ++];
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            
            mergeSort (arr, l, mid);
            mergeSort (arr, mid + 1, r);
            
            merge (arr, l, mid, r);
        }
    }
};


int main ()
{
    vector <int> arr = {64, -1, 30, 2, 5, 100, -10};
    Solution obj;
    obj.mergeSort(arr, 0, arr.size () - 1);

    for (auto value: arr) {
        cout << value << " ";
    }
}