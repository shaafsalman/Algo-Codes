#include <iostream>
using namespace std;

int partition(int arr[],int si,int ei)
{
    

}
void QuickSort(int arr[],int si,int ei)
{
    if(si,ei)
    {
        int pivotIndex = partition(arr,si,ei);
        QuickSort(arr,si,pivotIndex-1);
        QuickSort(arr,pivotIndex,ei);
    }

}


int main() {
    int arr[10] = {1, 10, 2, 6, 8, 55, 4, 32, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using Merge Sort
    QuickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
