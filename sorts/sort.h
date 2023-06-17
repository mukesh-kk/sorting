#include <vector>

#ifndef SORT_H
#define SORT_H
using namespace std;
vector<int> bubble_sort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    return arr;
}
void bubble_sort_byref(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    // return arr;
}
void bubble_sort_bypointer(vector<int> *arr)
{
    for (int i = 0; i < arr->size(); i++)
    {

        for (int j = 0; j < arr->size() - i - 1; j++)
        {
            if ((*arr)[j] > (*arr)[j + 1])
            {
                swap((*arr)[j], (*arr)[j + 1]);
            }
        }
    }
}
void bubble_sort_withiterator(vector<int>::iterator begin, vector<int>::iterator end)
{
    for (auto i = begin; i != end; ++i)
    {
        for (auto j = begin; j != end - 1; ++j)
        {
            if (*j > *(j + 1))
            {
                swap(*j, *(j + 1));
            }
        }
    }
}

/* selection sort*/

void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    int j = 0;
    for (int i = 1; i < n; i++)
    {

        int key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//  utils  for merge sort

void merge(vector<int> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[middle + 1 + i];
    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        merge_sort_(arr, left, middle);
        merge_sort_(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

void merge_sort(vector<int> &arr)
{

    merge_sort_(arr, 0, arr.size() - 1);
}

// quick_sort

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quick_sort_(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quick_sort_(arr, low, pivot - 1);
        quick_sort_(arr, pivot + 1, high);
    }
}
void quick_sort(vector<int> &arr)
{
    quick_sort_(arr, 0, arr.size() - 1);
}

#endif
