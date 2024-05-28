#include <iostream>
using namespace std;

// Function to merge two sorted subarrays
void Merge(int arr[], int si, int mid, int ei) {
    int merged[ei - si + 1]; // Temporary array to store merged subarrays
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;

    // Merge the two subarrays into the temporary array
    while (idx1 <= mid && idx2 <= ei) {
        if (arr[idx1] <= arr[idx2]) {
            merged[x++] = arr[idx1++];
        }
        else {
            merged[x++] = arr[idx2++];
        }
    }

    // Copy any remaining elements from the first subarray
    while (idx1 <= mid) {
        merged[x++] = arr[idx1++];
    }
    // Copy any remaining elements from the second subarray
    while (idx2 <= ei) {
        merged[x++] = arr[idx2++];
    }

    // Copy the merged array back to the original array
    for (int i = si; i <= ei; ++i) {
        arr[i] = merged[i - si];
    }
}

// Function to divide the array into smaller subarrays
void Divide(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;

    // Divide the left half of the array
    Divide(arr, si, mid);
    // Divide the right half of the array
    Divide(arr, mid + 1, ei);

    // Merge the divided subarrays
    Merge(arr, si, mid, ei);

    // Print the array at each level of division
    cout << "Array at level " << si << "-" << ei << ": ";
    for (int i = si; i <= ei; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {1, 10, 2, 6, 8, 55, 4, 32, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using Merge Sort
    Divide(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
