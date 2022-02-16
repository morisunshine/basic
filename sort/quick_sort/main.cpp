/* C implementation QuickSort */
#include <iostream>
#include <vector>
using namespace std;
// // A utility function to swap two elements
// void swap(int *a, int *b)
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

/* Function to print an array */
void printArray(vector<int>& nums)
{
    for (int itr : nums) {
       cout << itr << " ";
    }

    cout << "" << endl;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    printArray(arr);

    return (i + 1);
}

/* The main function that implements QuickSort
  arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Driver program to test above functions
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 1, 3, 4};
    vector<int> cost(arr, arr + sizeof(arr)/sizeof(arr[0]));
    cout << "Size of char : " << sizeof(arr) << endl;
    cout << "Size of char : " << sizeof(arr[0]) << endl;
    // int n = sizeof(arr) / sizeof(arr[0]);
    // quickSort(arr, 0, n - 1);
    quickSort(cost, 0, (int)cost.size() - 1);
    printArray(cost);
    return 0;
}