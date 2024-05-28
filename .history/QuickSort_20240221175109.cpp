#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei) {
    int pivot = arr[ei]; // Select the last element as the pivot
    int i = si - 1; // Index of the smaller element

    for (int j = si; j < ei; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    // Swap pivot element with element at index i+1
    swap(arr[i + 1], arr[ei]);
    return i + 1; // Return the partitioning index
}

void QuickSort(int arr[], int si, int ei) {
    if (si < ei) { // Ensure there are at least two elements
        int pivotIndex = partition(arr, si, ei);
        // Recursive calls on the partitions
        QuickSort(arr, si, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, ei);
    }
}

int main() {
    int arr[10] = {1, 10, 2, 6, 8, 55, 4, 32, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using Quick Sort
    QuickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
