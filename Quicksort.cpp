#include <iostream>

using namespace std;

// n^2 complexity at worst case
// nlogn at base case

int partition (int ara [], int start, int end) {
    int pi = start;
    int pivot = ara [end];

    for (int i = start; i < end; i ++) {
        if (ara [i] <= pivot) {
            swap (ara [i], ara [pi]);
            pi ++;
        }
    }

    swap (ara [pi], ara [end]);

    return pi;
}

void QuickSort (int a [], int start, int end) {
    if (start >= end) return;

    int pi = partition (a, start, end); 
    //pivot index
    // data form left side will be smaller and right side will be greater after the partition
    
    QuickSort (a, start, pi - 1);
    QuickSort (a, pi + 1, end);
}

int main ()
{
    int n, i;
    cin >> n;

    int *A = new int(n);

    for (i = 0; i < n; i ++) {
        cin >> A [i];
    }

    QuickSort (A, 0, n - 1);

    for (i = 0; i < n; i ++) cout << A [i] << " ";
}