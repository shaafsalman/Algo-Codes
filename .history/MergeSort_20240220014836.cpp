#include<iostream>
using namespace std;
  
 void Merge(int arr[], int si, int mid, int ei) {
    int merged[ei - si + 1];
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;

    while (idx1 <= mid && idx2 <= ei) {
        if (arr[idx1] <= arr[idx2]) {
            merged[x++] = arr[idx1++];
        }
        else {
            merged[x++] = arr[idx2++];
        }
    }

    while (idx1 <= mid) {
        merged[x++] = arr[idx1++];
    }
    while (idx2 <= ei) {
        merged[x++] = arr[idx2++];
    }

    for (int i = si; i <= ei; ++i) {
        arr[i] = merged[i - si];
    }
}

void Divide(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    Divide(arr, si, mid);
    Divide(arr, mid + 1, ei);
    Merge(arr, si, mid, ei);
}


int main()
{
     int arr[10] = {1, 10, 2, 6, 8, 55, 4, 32, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Divide(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}